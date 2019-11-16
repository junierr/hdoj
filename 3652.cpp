#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

long long dp[20][15][4];
int a[20];

long long dfs(int pos,int mod,int sta,bool limit){
	//mod 高位取余的结果 
    //sta 0:无13 1:无13，前一位为1 2:有13; 
	if(pos==-1)
	  return sta==2&&mod==0;
	if(!limit&&dp[pos][mod][sta]!=-1) 
	  return dp[pos][mod][sta];
	int up=limit?a[pos]:9;
	long long ans=0;
	for(int i=0;i<=up;i++){
		int pp=sta,hh=(mod*10+i)%13;
		if(sta==1&&i==3) pp=2;
		else if(sta!=2) pp=(i==1)?1:0;
		ans+=dfs(pos-1,hh,pp,limit&&i==up);
	}
	if(!limit) dp[pos][mod][sta]=ans;
	return ans; 
}


long long solve(long long x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,0,true);
}

int main(){
	long long n;
	memset(dp,-1,sizeof(dp));
	while(~scanf("%lld",&n)){
		printf("%lld\n",solve(n));
	}
	return 0;
}
