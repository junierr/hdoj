/*
ȡ��һ����С�Ĳ��ҿ�������n��3�ı������� 
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
	  	for(int i=0;i<63;i+=2){ //ȡ��%3��1�� 
	  		if((n>>i)&1){
	  			if(!b) b=1LL<<i;
	  			else if(!b1) b1=1LL<<i;
	  			else b2=1LL<<i;
			  }
		}
		for(int i=1;i<63;i+=2){  //ȡ��%3��2�� 
	  		if((n>>i)&1){
	  			if(!c) c=1LL<<i;
	  			else if(!c1) c1=1LL<<i;
	  			else c2=1LL<<i;
			  }
		}
		if(!b) b=c1|c2;//����%3��2�Ļ�һ��Ϊһ��%3��1�� 
		if(!c) c=b1|b2;//����%3��1�Ļ�һ��Ϊһ��%3��2��  
	    if(n%3==1){
	    	printf("2 %lld %lld\n",b|c,n^b);//�Ѷ����һλ��������֤Ϊ3�ı��� 
		}
		else if(n%3==2){
			printf("2 %lld %lld\n",b|c,n^c);
		} 
	}
	return 0;
}
