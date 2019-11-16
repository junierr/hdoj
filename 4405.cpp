#include<cstdio>
#include<cstring>
using namespace std;

int to[100005];
double dp[100005];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		memset(to,-1,sizeof(to));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			to[u]=v;
		}
		for(int i=n-1;i>=0;i--){
			if(to[i]!=-1) dp[i]+=dp[to[i]];
			else{
				for(int j=1;j<=6;j++){
					dp[i]+=1.0/6*(dp[i+j]+1);
				}
			}
		}
		printf("%.4f\n",dp[0]);
	}
	return 0;
}
