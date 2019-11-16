#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
long long dp[100005];


void solve(){
	dp[1]=dp[2]=dp[3]=1;
	for(int i=4;i<=100000;i++){
		dp[i]=dp[i-1]+dp[i-3];
		if(dp[i]>mod) dp[i]-=mod;
	}
}

int main(){
	int T,n,x,y;
	scanf("%d",&T);
	solve();
	while(T--){
		scanf("%d%d%d",&n,&x,&y);
		if(x==1&&y==n)
		  printf("%lld\n",dp[n]);
		else if(x==1) 
		  printf("%lld\n",dp[y-1]);
		else if(y==n)
		  printf("%lld\n",dp[n-x]);
		else printf("%lld\n",dp[y-x-1]);      
	}
	return 0;
} 
