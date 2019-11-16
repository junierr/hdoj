#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long mod= 998244353;
char s[3005],t[3005];

long long dp[3005][3005];
long long c[3005][3005];
int n,m;

void init(){
	for(int i=0;i<=3000;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}


void solve(){
	long long ans=0;
	for(int i=1;i<=m;i++){ //起点 
		if(s[i]!='0'){
			for(int j=n;j<=m-i;j++){
				ans=(ans+c[m-i][j])%mod;
			}
		}
	}
	//以上是所有长度大于n的开头不为0的子序列 
	for(int i=0;i<=m;i++)
	  for(int j=0;j<=n;j++)
	    dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=m;i++){  //dpij代表s的前i位与t有j位相等的方案数 
		dp[i][0]=1;
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j];//初始为s的前i-1位与t有j位相等的方案数 
			if(s[i]==t[j]){
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;//如果第i位相等就加上前i-1位有j-1位相等的方案数 
			}
			else if(s[i]>t[j])
			  ans=(ans+dp[i-1][j-1]*c[m-i][n-j])%mod;//默认选了此时大于的那一位，所以不会重复 
		}
	}
	printf("%lld\n",ans);    
}

int main(){
	int T;
	scanf("%d",&T);
	init();
	while(T--){
		scanf("%d%d",&m,&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		solve();
	}
	return 0;
} 
