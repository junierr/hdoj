/*
beautiful数为一个递减数，上一位对下一位求余==0 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[20];
int dp[20][20];

int  dfs(int pos,int sta,bool lead,bool limit){ 
//sta:前一个数 lead:true:最前面都是0 
	if(pos==-1) return 1;
	if(!limit&&dp[pos][sta]!=-1)
	  return dp[pos][sta];
	int up=limit?a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
	   if(!lead&&i==0) continue;  //前面不是0，当前是0（不可能） 
	 	if(lead){
			ans+=dfs(pos-1,i,lead&&i==0,limit&&i==up);
			continue;
		}
		if(i>sta&&sta!=-1) break;
		if(sta%i!=0&&sta!=-1) continue;
		ans+=dfs(pos-1,i,lead&&i==0,limit&&i==up);
	}  
	if(!limit&&!lead) dp[pos][sta]=ans;
	return ans;
}




int solve(int x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,-1,true,true);
}


int main(){
	int T,l,r;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	while(T--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(r)-solve(l-1));
	}
	return 0;
} 
