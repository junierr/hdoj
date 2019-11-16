#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


long long dp[20][20][20];
int a[30];

long long dfs(long long pos,int pre,int sta,bool limit){
	//pos:��ǰλ��;pre:��һλֵ;sta:n/ǰ������49��n��,0/ǰ�治����49��limit:false/��һλ������;true:��һλ����) 
	if(pos==-1)
	  return sta!=0;
	if(!limit&&dp[pos][pre][sta]!=-1)
	  return dp[pos][pre][sta];  
	  int up=limit?a[pos]:9;
	  long long ans=0;
	  for(int i=0;i<=up;i++){
	  	if(pre==4&&i==9)
	  	  ans+=dfs(pos-1,i,sta+1,limit&&i==up);
	  	else ans+=dfs(pos-1,i,sta||0,limit&&i==up);  
	  }
	  if(!limit) dp[pos][pre][sta]=ans;
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
	int T;
	long long r;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	while(T--){
		scanf("%lld",&r);
		printf("%lld\n",solve(r));
	}
	return 0;
}
