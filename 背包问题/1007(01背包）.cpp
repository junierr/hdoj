#include<bits/stdc++.h> 
using namespace std;
int main()
{
    long long n,m,i,j;
    long long a[10005];
    double b[10005],dp[10005];
	while(~scanf("%lld%lld",&n,&m)&&m+n)
    {
    	for(i=1;i<=m;i++)
    	{
    		scanf("%lld%lf",&a[i],&b[i]);
		}
		fill(dp,dp+n+1,1);
		for(i=1;i<=m;i++)
		{
			for(j=n;j>=a[i];j--)
			{
				dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
			}
		}
		printf("%.1f%%\n",(1-dp[n])*100);
	}
	return 0;
} 
