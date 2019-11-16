#include<bits/stdc++.h>
using namespace std;

int dp[2][100005];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int p,g;
		scanf("%d%d",&p,&g);
		for(int j=m;j>=p;j--){
			dp[i&1][j]=dp[(i-1)&1][j-p];//买了这台主机 (滚动数组与i-1有关)
		}
		int c,w;
		for(int j=1;j<=g;j++){
			scanf("%d%d",&c,&w);
			for(int k=m;k>=c+p;k--){
				dp[i&1][k]=max(dp[i&1][k],dp[i&1][k-c]+w);
			}
		}
		for(int j=m;j>=0;j--){
			dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]);//选与不选 
		}
	}
	printf("%d\n",dp[n&1][m]);
	return 0;
}
