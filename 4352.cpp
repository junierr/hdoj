/*
二进制从右往左
第k个1即代表长度为k递增子序列末尾最小的值（值大小=从右往左位置）
详情见LIS的nlogn算法
然后套数位dp 
*/


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[30],m;
long long dp[30][3000][12];


int make(int s,int x){
	for(int i=x;i<=9;i++){
		if(s&(1<<i)){
			s^=(1<<i);
			break;
		}
	}
	return s|(1<<x);
}



int count(int x){
	int ans=0;
	while(x){
		if(x&1)
		  ans++;
		x>>=1;  
	}
	return ans;
}


long long dfs(int pos,int sta,bool lead,bool limit){
	if(pos==-1) return (count(sta)==m);
	if(!lead&&!limit&&dp[pos][sta][m]!=-1)
	  return dp[pos][sta][m];
	int up=limit?a[pos]:9;
	long long ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,(lead&&i==0)?0:make(sta,i),lead&&i==0,limit&&i==up);
	}
	if(!limit&&!lead) dp[pos][sta][m]=ans;
	return ans; 
}




long long solve(long long x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,true,true);
}



int main(){
	long long l,r;
	int T;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=T;i++){
		scanf("%lld%lld%d",&l,&r,&m);
		printf("Case #%d: %lld\n",i,solve(r)-solve(l-1));
	}
	return 0;
}
