#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,i,j,n,m,k;
	long long p[105],h[105],c[105];
	long long dp[10000];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=m;i++)
		{
			cin>>p[i]>>h[i]>>c[i];
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=c[i];j++)
			{
				for(k=n;k>=p[i];k--)
				{
					dp[k]=max(dp[k],dp[k-p[i]]+h[i]);
				}
			}
	    }
	cout<<dp[n]<<endl;    
    }
	return 0;
}
