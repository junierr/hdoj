#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long mod=1e9+7;
struct node{
	long long cnt,sum1,sum;
	//cnt记录该dp状态下符合的数字有几个,sum1记录平方和，sum用来维护平方和 （除第一位外剩下的数，如1234，sum即为234）
	//公式：1234^2=1000^2+2*1000*234+234^2; 
}dp[20][2][10][10];

int a[25];

long long pp(int x){
	long long t=1;
	while(x--){
		t*=10;
		t%=mod;
	}
	return t;
}

node dfs(int pos,int pre,int sta,int sa,int sb,bool limit){
	//sa:和取余 sb:数取余 
	if(pos==-1){
		if(sta==1||sa%7==0||sb%7==0){
	      return node{0,0,0};
		}
		else {
			return node{1,0,0};
		}
	}
	if(!limit&&dp[pos][sta][sa][sb].cnt!=-1)
	  return dp[pos][sta][sa][sb];
	int up=limit?a[pos]:9;
	node tmp;
	tmp.cnt=0;tmp.sum=0;tmp.sum1=0;
	for(int i=0;i<=up;i++){
		node tnp=dfs(pos-1,i,sta||i==7,(sa+i)%7,(sb*10+i)%7,limit&&i==up);
		if(tnp.cnt>=1){
			long long x=i*pp(pos);
			x%=mod;
			tmp.cnt+=tnp.cnt;
			tmp.cnt%=mod;
			if(pos==0){
				tmp.sum+=i;
			}
			else {
				tmp.sum+=tnp.sum+x*tnp.cnt%mod;
			}
			tmp.sum%=mod;
			tmp.sum1+=(((x*x)%mod)*tnp.cnt)%mod+((2*x)%mod)*tnp.sum%mod+tnp.sum1%mod;
			tmp.sum1%=mod;
		}
		if(!limit)
		  dp[pos][sta][sa][sb]=tmp;
	}  
	return tmp;
}




node solve(long long x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,-1,0,0,0,true);
}



int main(){
   	memset(dp,-1,sizeof(dp));
   	int T;
   	long long l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(solve(r).sum1-solve(l-1).sum1+mod)%mod);
	}
	return 0;
} 
