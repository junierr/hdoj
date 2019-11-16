#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


double dp[1005][1005],p[1005][1005][4];

int main(){
	int r,c;
	while(~scanf("%d%d",&r,&c)){
		for(int i=1;i<=r;i++)
		  for(int j=1;j<=c;j++)
		    for(int k=1;k<=3;k++){
		      scanf("%lf",&p[i][j][k]);
		       dp[i][j]=0;
		   }
		for(int i=r;i>=1;i--)
		  for(int j=c;j>=1;j--){
		  	if(i==r&&j==c||p[i][j][1]==1) 
			    continue;//´ýÔÚÔ­µØ;
			dp[i][j]=(p[i][j][2]*dp[i][j+1]+p[i][j][3]*dp[i+1][j]+2)/(1.0-p[i][j][1]);   
		  }
		  printf("%.3f\n",dp[1][1]);   
	}
	return 0;
} 
