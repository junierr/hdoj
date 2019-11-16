#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main(){
	int p,e,i,d,T;
	scanf("%d",&T);
	int count=1;
	while(~scanf("%d%d%d%d",&p,&e,&i,&d)){
		int n;
		if(p==-1&&e==-1&&i==-1&&d==-1) break;
		n=(5544*p+14421*e+1288*i-d+21252)%21252;
		if(n==0)
		  n=21252;
		 printf("Case %d: the next triple peak occurs in %d days.\n",count++,n);
	}
	return 0;
}
