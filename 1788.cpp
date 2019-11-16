#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long a,lcm;
long long m[100];
bool flag;

long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

long long e_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	long long ans=e_gcd(b,a%b,y,x);
	y-=a/b*x;
	return ans;
}

long long china(long long I){
	long long a1=m[0],b1=m[0]-a;
	long long a2,b2,k1,k2,c,g,x0;
	lcm=m[0];
	for(long long i=1;i<I;i++){
		a2=m[i];
		b2=m[i]-a;
		c=b2-b1;
		g=e_gcd(a1,a2,k1,k2);
		lcm=lcm*m[i]/gcd(lcm,m[i]);
		flag=true;
		if(c%g){
			flag=false;
			return 0;
		}
		x0=k1*c/g;
		long long t=a2/g;
		x0=(x0%t+t)%t;
		b1+=a1*x0;
		a1=a1*a2/gcd(a1,a2);
	}
	return b1;
}




int main(){
	long long I;
	while(~scanf("%lld%lld",&I,&a)){
		if(I==0&&a==0) break;
		for(long long i=0;i<I;i++)
		  scanf("%lld",&m[i]);
		printf("%lld\n",china(I));  
	}
	return 0;
} 
