#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6+20;
const int Max = 99999999;
const int Min = -99999999;
const int inf = INT_MAX;
const int mod = 1000000007;
typedef long long ll;
ll ans=0;
ll a[maxn],b[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%lld",&b[i]),ans=max(ans,a[i]*b[i]);
    ll s=0,mi=Max;
    for(int i=0;i<n;i++)//a[i]+
    {
        if(s+b[i]>=0)//包含所有情况了 
        {
            s+=b[i];
            mi=min(mi,a[i]);
        }
        else
        {
            s=0;
            mi=Max;
        }
        ans=max(ans,s*mi);
    }
    for(int i=0;i<n;i++)a[i]=-a[i],b[i]=-b[i];
    ll mx=Min;
    s=0;
    for(int i=0;i<n;i++)//a[i]-
    {
        if(s+b[i]>=0)
        {
            s+=b[i];
            mx=max(mx,a[i]);
        }
        else
        {
            s=0;
            mx=Min;
        }
        ans=max(ans,s*mx);
    }
    printf("%lld",ans);
}
