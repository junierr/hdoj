#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,t,j,k;
	long long dp[10005];
    int a[10]={0,150,200,350};
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=3;i++)
		{
			for(j=n;j>=0;j--)
			{
				for(k=1;k*a[i]<=j;k++)
				{
					dp[j]=max(dp[j],dp[j-k*a[i]]+k*a[i]);
				}
			}
		}
		cout<<n-dp[n]<<endl;
	}
	return 0;
 } 
