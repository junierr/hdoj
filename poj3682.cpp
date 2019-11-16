/*
因为抛硬币为独立事件，所以E（k）=k/p；
花费：F[k]=p*F[k-1]+(1-p)*F[k]+2*E(k)-1;
累加法得到F[k]=k(k+1)/p^2-k/p; 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n;double p;
	while(~scanf("%d",&n)&&n){
		scanf("%lf",&p);
		printf("%.3f %.3f\n",n/p,n*(n+1)/(p*p)-n/p);
	}
	return 0;
} 
