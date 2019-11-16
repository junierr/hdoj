#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[20];
int dp[20][2];

int dfs(int pos,int pre,int sta,bool limit){
	if(pos==-1) return 1; //������ 
	if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta]; //���仯(��һλû�дﵽ���ޣ�˵�����dp����ֱ����) 
	int up=limit?a[pos]:9;//ȡ���ޣ�ture˵����һλ�Ѿ��ﵽ���ޣ���ǰλ�����ƣ�false˵�������� 
	int tmp=0;
	for(int i=0;i<=up;i++){
		if(pre==6&&i==2) continue;
		if(i==4) continue;
		tmp+=dfs(pos-1,i,i==6,limit&&i==a[pos]);
	}
	if(!limit) dp[pos][sta]=tmp;
	return tmp;
}


int solve(int x){  //�ֽ���λ 
 	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,-1,0,true);
}

int main(){
	int l,r;
	while(~scanf("%d%d",&l,&r)){
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(r)-solve(l-1));
	}
	return 0;
} 
