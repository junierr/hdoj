#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int a[2005],dp[2005][2005];

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=k;i++)
		  for(int j=1;j<=n;j++){
		  	if(i*2<=j)
		  	  dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]));
		  	else dp[i][j]=inf;  
		  }
		printf("%d\n",dp[k][n]);    
	}
	return 0;
} 
