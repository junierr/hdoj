#include<bits/stdc++.h>
using namespace std;

double dp[1<<10][1<<10];
double p[15][1005];

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n,m;
        int len1=1<<10;
		for(int i=0;i<len1;i++)
		  for(int j=0;j<len1;j++)
		    dp[i][j]=-1;
		dp[0][0]=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++)
		    scanf("%lf",&p[i][j]);
		int len=1<<n;
		int st;
		dp[0][0]=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<len;j++){
				if(dp[i][j]==-1) continue;
				for(int k=0;k<n;k++){
					if(!(j&(1<<k))){
						st=j|(1<<k);
						if(st==(1<<n)-1)
						  st=0;
						dp[i+1][st]=max(dp[i+1][st],dp[i][j]+p[k][i]);  
					}	  
				}
			}
		}
		double ans=0;
		for(int i=0;i<len;i++){
			ans=max(ans,dp[m][i]);
		}
		printf("Case #%d: %.5lf\n", t, ans);	    
	}
	return 0;
}
