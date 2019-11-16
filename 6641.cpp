#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
    while(b != 0)
    {
        long long r = b;
        b = a%b;
        a = r;
    }
    return a;
} 

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long k;
		int m;
		scanf("%lld%d",&k,&m);
		long long n=max(1LL,k-1050);
		int cnt=0,flag1,flag2;
		long long t;
		for(n;n<=k+1050;n++){
			flag1=0;
			flag2=0;
			cnt=0;
			for(t=n+1;t;t++){
				if(gcd(t,n)==1) cnt++;
				if(cnt==m) {
					flag2=1;
					break;
				}
			}
			if(flag2==1&&t==n+(k^n)){
				flag1=1;
				break;
			}
		}
		if(flag1==1){
			printf("%lld\n",n);
		}
		else printf("-1\n");
	}
	return 0;
} 
