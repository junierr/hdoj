/*
先比整数部分，再叉乘比小数部分 
*/

#include<cstdio>
#include<cstring>
using namespace std;


long long a,b,x,y;

int main(){
	while(~scanf("%lld%lld%lld%lld",&x,&a,&y,&b)){
		long long q1=x/a;
		long long q2=y/b;
		if(q1>q2){
			printf(">\n");
			continue;
		}
		else if(q1<q2){
			printf("<\n");
			continue;
		}
		else{
			long long w1=x%a*b;
			long long w2=y%b*a;
			if(w1>w2){
				printf(">\n");
				continue;
			}
			else if(w1<w2){
				printf("<\n");
				continue;
			}
			else{
				printf("=\n");
			}
		}
	}
	return 0;
}
