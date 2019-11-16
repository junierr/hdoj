/*
数字符合字符串所给的上升或下降趋势 
*/


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod =1e8;
int dp[105][12][105],len,a[105];
char s[105];

bool check(int x,int y,char c){
	if(c=='/'&&x<y) return true;
	if(c=='-'&&x==y) return true;
	if(c=='\\'&&x>y) return true;
	return false;
} 


long long dfs(int pos,int pre,int p,bool lead,bool limit){
	if(pos==-1) return p==len;
	if(!limit&&!lead&&dp[pos][pre][p]!=-1)
	  return dp[pos][pre][p];
	int up=limit?a[pos]:9;  
	long long ans=0;
	for(int i=0;i<=up;i++){
		if(lead) ans=(ans+dfs(pos-1,i,p,lead&&i==0,limit&&i==up))%mod;
		else if(p<len&&check(pre,i,s[p+1]))
		  ans=(ans+dfs(pos-1,i,p+1,lead&&i==0,limit&&i==up))%mod;
		else if(p>0&&check(pre,i,s[p]))
		  ans=(ans+dfs(pos-1,i,p,lead&&i==0,limit&&i==up))%mod;     
	}
	if(!limit&&!lead) dp[pos][pre][p]=ans%mod;
	return ans%mod;
}


long long solve1(char x[]){
	int i=0,pos=0;
	while(x[i]=='0') i++;
	if(x[i]=='\0') return 0;
	int len1=strlen(x);
	for(int j=len1-1;j>=i;j--){
		a[pos++]=x[j]-'0';
	}
	return dfs(pos-1,0,0,true,true);
}
long long solve2(char x[]){
	int i=0,pos=0;
	while(x[i]=='0') i++;
	if(x[i]=='\0') return 0;
	int len1=strlen(x);
	for(int j=len1-1;j>=i;j--){
		a[pos++]=x[j]-'0';
	}
	a[0]--;
	for(int j=0;j<pos;j++){
		if(a[j]<0){
			a[j]+=10;
			a[j+1]--;
		}
		else break;
	}
	if(a[pos-1]==0) pos--;
	return dfs(pos-1,0,0,true,true);
}


int main(){
	char s1[105],s2[105];
	while(~scanf("%s",s+1)){
		memset(dp,-1,sizeof(dp));
		len=strlen(s+1);
		scanf("%s%s",s1,s2);
		long long r=solve1(s2);
		long long l=solve2(s1);
		printf("%08lld\n",(r-l+mod)%mod);//加mod是为了避免r<l的情况 
	}
	return 0;
} 
