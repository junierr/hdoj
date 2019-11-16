#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long catalan[38];

int main(){
	catalan[1]=1;
	int t=1;
	int n;
	for(int i=2;i<=36;i++){
		for(int j=1;j<i;j++)
		  catalan[i]+=catalan[j]*catalan[i-j];
	}
	while(~scanf("%d",&n)){
		if(n==-1) break;
		printf("%d %d %lld\n",t++,n,2*catalan[n+1]);
	}
	return 0;
}
