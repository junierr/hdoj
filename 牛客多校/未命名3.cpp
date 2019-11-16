#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000006;
int n;
int x[maxn];
int y[maxn];
long long q[maxn];
 
template <class T>
void read(T &x) {
    static char ch;static bool f;
    for(ch=f=0;ch<'0' || '9'<ch;f|=ch=='-',ch=getchar());
    for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
    x=f?-x:x;
}
 
struct node
{
    int l,r;
    long long minn;
    long long maxx;
#define l(x)  tree[x].l
#define r(x)  tree[x].r
#define minn(x)  tree[x].minn
#define maxx(x)  tree[x].maxx
} tree[maxn*4];
struct danDiaoZhanNode
{
    long long val,beginn,endd,locate;
    danDiaoZhanNode() {}
    danDiaoZhanNode(long long val,long long beginn,long long endd,long long locate)
    {
        this->val = val;
        this->beginn = beginn;
        this->endd = endd;
        this->locate = locate;
    }
} Stack[maxn+10];
 
void build(int p,int l,int r)
{
    l(p) = l;
    r(p) = r;
    if(l == r)
    {
        minn(p) = q[l];
        maxx(p) = q[l];
        return;
    }
    int mid= (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    minn(p) = min(minn(p*2),minn(p*2+1));
    maxx(p) = max(maxx(p*2),maxx(p*2+1));
}
long long askmax(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p))
    {
        return maxx(p);
    }
    int mid  = (l(p)+r(p))/2;
    long long val = -1000000000000-1;
    if(l<=mid)
    {
        val = max(val,askmax(p*2,l,r));
    }
    if(r>mid)
    {
        val = max(val,askmax(p*2+1,l,r));
    }
    if(l <= 0||r<=0)
    {
        val = max(0ll,val);
    }
    return val;
}
long long askmin(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p))
    {
        return minn(p);
    }
    int mid  = (l(p)+r(p))/2;
    long long val = 1000000000000+1;
    if(l<=mid)
    {
        val = min(val,askmin(p*2,l,r));
    }
    if(r>mid)
    {
        val = min(val,askmin(p*2+1,l,r));
    }
    if(l <= 0||r<=0)
    {
        val = min(0ll,val);
    }
    return val;
}
int top = 0;
long long work()
{
    build(1,1,n);
    x[n+1] = -3000000-6;
    Stack[0] = danDiaoZhanNode(-1000000000000-1,0,0,0);
    long long ans = -1000000000000-1;
    for(int i = 1; i<=n+1; i++)
    {
        if(x[i]>Stack[top].val)
        {
            //cout<<"insert"<<x[i]<<endl;
            Stack[++top] = danDiaoZhanNode(x[i],i,i,i);
        }
        else
        {
            long long beginn = Stack[top].beginn;
            long long endd = Stack[top].endd;
            long long sum;
            while(Stack[top].val>x[i])
            {
                //cout<<"pop"<<Stack[top].val<<endl;
                beginn = Stack[top].beginn;
                if(Stack[top].val>0)
                {
                    sum = askmax(1,Stack[top].locate, endd) - askmin(1,beginn-1,Stack[top].locate-1);
                    //cout<<Stack[top].locate<<"--"<<endd<<"   "<<beginn-1<<"--"<<Stack[top].locate-1<<endl;
                    //cout<< askmax(1,Stack[top].locate , endd)<<" - " <<askmin(1,beginn-1,Stack[top].locate-1)<<endl;
                    ans = max(ans,sum*Stack[top].val);
                }
                else if(Stack[top].val<0)
                {
                    sum = askmin(1,Stack[top].locate, endd) - askmax(1,beginn-1,Stack[top].locate-1);
                    ans = max(ans,sum*Stack[top].val);
                }
                else
                {
                    ans = max(ans,0ll);
                }
                //cout<<beginn<<" "<<endd<<endl;
                //cout<<sum<<"*"<<Stack[top].val<<endl;
                top--;
 
            }
            //cout<<"insert"<<x[i]<<endl;
            Stack[++top] = danDiaoZhanNode(x[i],beginn,i,i);
        }
    }
    return ans;
}
 
int main()
{
    read(n);
    for(int i = 1; i<=n; i++)
    {
        read(x[i]);
    }
    for(int i = 1; i<=n; i++)
    {
        read(y[i]);
        q[i] = q[i-1]+y[i];
    }
    printf("%lld",work());
}
