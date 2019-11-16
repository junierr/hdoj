#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int maxn=205;
int dp[maxn][maxn];
int a[maxn],b[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		  scanf("%d",&b[i]);
		printf("Case #%d: ",t);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		  for(int j=i;j<=n;j++)
		    dp[i][j]=inf;
		for(int len=0;len<=n;len++){
			for(int l=1;l<=n-len;l++){
				int r=l+len;
				for(int k=l;k<=r;k++)
				  dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]+a[k]+b[l-1]+b[r+1]);
			}
		}
		printf("%d\n",dp[1][n]);	    
	}
	return 0;
}
