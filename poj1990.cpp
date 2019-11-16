#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long c1[20005];//niu de shu liang
long long c2[20005];//zuo biao he 
struct pp
{
	long long v;
	long long x;
}s[20005];
bool cmp(pp x, pp y)
{
   return x.v<y.v;
}

long long lowbit(long long x)
{
  return (x&(-x));	
}

void update(long long c[],long long x,long long y)
{
	for(;x<20005;c[x]+=y,x+=lowbit(x));
}

long long sum(long long c[],long long x)
{
	long long ret=0;
	for(;x>0;ret+=c[x],x-=lowbit(x)); 
	return ret;
}

int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=1;i<=n;i++)
		  scanf("%lld%lld",&s[i].v,&s[i].x);
		sort(s+1,s+n+1,cmp);
		long long ans=0;
		update(c1,s[1].x,1);
		update(c2,s[1].x,s[1].x);  
		for(i=2;i<=n;i++)
		{
		   long long n1=sum(c1,s[i].x);
		   long long m1=sum(c2,s[i].x);
		   long long m2=sum(c2,20004);
		   ans+=s[i].v*(n1*s[i].x-m1+m2-m1-(i-n1-1)*s[i].x); //hua tu ji suan ju li
		   update(c1,s[i].x,1);
		   update(c2,s[i].x,s[i].x);
		}
		printf("%lld\n",ans);
	}
	return 0;
 } 
