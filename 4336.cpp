#include<bits/stdc++.h>
using namespace std;

const int N=20;
int n;
double dp[1<<N];//二进制状压 代表该状态下需要买的期望 
double p[N];

int main(){
	while(~scanf("%d",&n)){
		double pp=0;
		for(int i=0;i<n;i++){
			scanf("%lf",&p[i]);
			pp+=p[i];
		}
		memset(dp,0,sizeof(dp));
		pp=1-pp;//抽不到牌的概率 
		dp[(1<<n)-1]=0;//1111时代表全买了，还需要的期望为0 
		for(int i=(1<<n)-2;i>=0;i--){
			double x=0;
			double s=1;//买一包
			for(int j=0;j<n;j++){//遍历所有状态 
				if(i&(1<<j)) x+=p[j];//已买过
				else s+=p[j]*dp[i|(1<<j)];//把所有没买过的状态都加上(总期望) 
			} 
			dp[i]=s/(1-pp-x);//总期望/抽到没买过卡的概率 
		}
		printf("%.4lf\n",dp[0]);
	}
	return 0;
}
