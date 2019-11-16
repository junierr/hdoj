#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,j,k,sum;
	long long dp[200005],v[10005],m[10005];
	while(cin>>n&&n>0)
	{
		sum=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			cin>>v[i]>>m[i];
			sum+=v[i]*m[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=sum/2;j>=v[i];j--)
			{
				for(k=1;k<=m[i]&&k*v[i]<=j;k++)
				{
					dp[j]=max(dp[j],dp[j-k*v[i]]+k*v[i]);
				}
			}
		}
	cout<<sum-dp[sum/2]<<" "<<dp[sum/2]<<endl;	
	}
	return 0;
} 
