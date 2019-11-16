/*
f[i]代表到i+1的期望
f[i]=pi*a+(1-pi)*(a+f[x]+...+f[i])
推出pif[i]=a+(1-pi)(f[x]+...+f[i-1])  令tmp=f[x]+..+f[i-1]=sum[i-1]-sum[x-1]
f[i]=[a+(1-pi)*tmp]/pi
f[i]+tmp=(a+tmp)/pi 


*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll sum[500005];
const ll mod=1e9+7;

ll quick(ll a, ll n)
{
   ll ans = 1;
   while (n) {
       if (n & 1) ans = ans * a % mod;
       a = a * a % mod;
       n >>= 1;
   }
    return  ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,Q;
		scanf("%d%d",&n,&Q);
		for(int i=1;i<=n;i++){
			int p,q,x,a;
			scanf("%d%d%d%d",&p,&q,&x,&a);
			ll tmp=(sum[i-1]-sum[x-1]+mod)%mod;
			sum[i]=(a+tmp)%mod*q%mod*quick((long long)p,mod-2)%mod;
			sum[i]=(sum[i]-tmp+mod)%mod;
			sum[i]=(sum[i]+sum[i-1])%mod;
		}
		while(Q--){
			int L,R;
			scanf("%d%d",&L,&R);
			printf("%lld\n",(sum[R-1]-sum[L-1]+mod)%mod);
		}
	}
	return 0;
}
