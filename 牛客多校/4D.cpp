/*
取出一个最小的并且可以异或掉n的3的倍数即可 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	long long n;
	while(T--){
		scanf("%lld",&n);
		if(n%3==0){
		printf("1 %lld\n",n);
		continue; 
	  	}
	  	long long b=0,b1=0,b2=0;
	  	long long c=0,c1=0,c2=0;
	  	for(int i=0;i<63;i+=2){ //取出%3余1的 
	  		if((n>>i)&1){
	  			if(!b) b=1LL<<i;
	  			else if(!b1) b1=1LL<<i;
	  			else b2=1LL<<i;
			  }
		}
		for(int i=1;i<63;i+=2){  //取出%3余2的 
	  		if((n>>i)&1){
	  			if(!c) c=1LL<<i;
	  			else if(!c1) c1=1LL<<i;
	  			else c2=1LL<<i;
			  }
		}
		if(!b) b=c1|c2;//两个%3余2的或一下为一个%3余1的 
		if(!c) c=b1|b2;//两个%3余1的或一下为一个%3余2的  
	    if(n%3==1){
	    	printf("2 %lld %lld\n",b|c,n^b);//把多的那一位异或掉，保证为3的倍数 
		}
		else if(n%3==2){
			printf("2 %lld %lld\n",b|c,n^c);
		} 
	}
	return 0;
}
