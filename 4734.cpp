/*
��ÿ����ͬ��a��dpֵ���б仯����͵���Ҫ��һ��״̬���������dp[pos][all-sta]��=����ʣ�µ�
ֵ�����ڼ�λʱ���ʣ�µ�ֵ�����ҹ��Ͳ��ø�����
sta������a�й�
all-sta������a�޹� 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int all;
int dp[12][5000];
int a[12];

int f(int x){
	if(x==0) return 0;
	int ans=f(x/10);
	return ans*2+(x%10);
}

int dfs(int pos,int sta,bool limit){
	if(pos==-1) return sta<=all;
	if(sta>all) return 0;
	if(!limit&&dp[pos][all-sta]!=-1)
	  return dp[pos][all-sta];
	int up=limit?a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,sta+i*(1<<pos),limit&&i==up);
	}  
	if(!limit) dp[pos][all-sta]=ans;
	return ans;
}



int solve(int x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,true);
}



int main(){
	int T,a,b;
	int k=1;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	while(T--){
		scanf("%d%d",&a,&b);
		all=f(a);
		printf("Case #%d: %d\n",k++,solve(b));
	}
	return 0;
}
