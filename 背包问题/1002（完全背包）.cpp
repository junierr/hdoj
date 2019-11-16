#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,i,e,f,n,j; 
	long long dp[20000],p[20000],w[20000];
 	cin>>t;
	while(t--)
	{
		cin>>e>>f;
		cin>>n;
		for(i=1;i<=n;i++) cin>>p[i]>>w[i];
		for(i=1;i<=f-e;i++) dp[i]=99999999;
		dp[0]=0; 
		for(i=1;i<=n;i++)
		{
			for(j=w[i];j<=f-e;j++)
			{
				 dp[j]=min(dp[j],dp[j-w[i]]+p[i]); 
			}
		}
		if(dp[f-e]==99999999) cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<"."<<endl;
	}
	return 0;
 } 
