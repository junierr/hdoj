/*
(m+1)*r+s
第一次取走s，之后每次留下m+1的倍数，即可获胜 
*/


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;



int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n%(m+1)==0)printf("second\n");
		else printf("first\n");
		}  
	return 0;
}
