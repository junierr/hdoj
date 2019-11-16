/*
(i-j)*a[i]=0; 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long dp[20][20][2005];
int a[30];

long long dfs(int pos,int o,int sta,bool limit){
	//o:֧�� sta:���� 
	if(pos==-1)
	  return sta==0;
	if(sta<0) return 0;  
	if(!limit&&dp[pos][o][sta]!=-1)
	  return dp[pos][o][sta];
	long long ans=0;
	int up=limit?a[pos]:9;
	for(int i=0;i<=up;i++){  //ö�ٸ�λ�� 
		ans+=dfs(pos-1,o,sta+(pos-o)*i,limit&&i==up);
	} 
	if(!limit) dp[pos][o][sta]=ans;
	return ans;   
}


long long solve(long long x){
	int pos=0;
	long long ans=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	} 
	for(int i=0;i<pos;i++)  //ö��֧�� 
	  ans+=dfs(pos-1,i,0,true);
	return ans-pos; //�������0-x������00000(����Ϊpos)������pos�� 
}


int main(){
	int T;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	while(T--){
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
