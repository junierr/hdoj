#include<cstdio>
#include<cstring>
using namespace std;

long long n,m,x;
int a[1000005];

int main(){
	while(~scanf("%lld%lld",&n,&m)){
		memset(a,0,sizeof(a));
		for(long long i=0;i<n;i++)
		{
			scanf("%lld",&x);
			a[x+500000]=1;
		}
		long long t=1;
		for(long long i=1000004;i>=0;i--){
			if(a[i]==1&&t!=m){
				printf("%lld ",i-500000);
				t++;
			}
			else if(a[i]==1){
				printf("%lld\n",i-500000);
				break;
			}
		}
	}
	return 0;
} 
