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
	for(int i=1;i<=m;i++){ //��� 
		if(s[i]!='0'){
			for(int j=n;j<=m-i;j++){
				ans=(ans+c[m-i][j])%mod;
			}
		}
	}
	//���������г��ȴ���n�Ŀ�ͷ��Ϊ0�������� 
	for(int i=0;i<=m;i++)
	  for(int j=0;j<=n;j++)
	    dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=m;i++){  //dpij����s��ǰiλ��t��jλ��ȵķ����� 
		dp[i][0]=1;
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j];//��ʼΪs��ǰi-1λ��t��jλ��ȵķ����� 
			if(s[i]==t[j]){
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;//�����iλ��Ⱦͼ���ǰi-1λ��j-1λ��ȵķ����� 
			}
			else if(s[i]>t[j])
			  ans=(ans+dp[i-1][j-1]*c[m-i][n-j])%mod;//Ĭ��ѡ�˴�ʱ���ڵ���һλ�����Բ����ظ� 
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
