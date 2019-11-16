#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,i,k,j;
	long long dp[100005],a[105],b[105];
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
		cin>>m;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			for(j=m;j>=0;j--) 
			{
				for(k=1;k*b[i]<=j;k++)
				{
					dp[j]=max(dp[j],dp[j-k*b[i]]+k*a[i]);
				}
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}
