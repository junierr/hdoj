#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int T,n,m,p[1000],h[1000],c[1000];
	int dp[1000];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&p[i],&h[i],&c[i]);	
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			for(int j=n;j>=p[i];j--){
				for(int k=0;k<=c[i];k++){
					if(j>=k*p[i]){
						dp[j]=max(dp[j],dp[j-k*p[i]]+h[i]*k);
					}
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
} 
