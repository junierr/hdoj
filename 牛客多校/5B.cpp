#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
#define N 10000005
using namespace std;

ll mod;
char s[N];

struct mat{
	ll a[3][3];
	mat() {
		memset(a,0,sizeof(a));
	}
	void init(){
		a[0][0]=1;
		a[1][1]=1;
	}
	
};

mat mul(mat a,mat b){
		mat c;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return c;
	}
	
mat poww(mat a,int n){
	mat ans;
	ans.init();
	while(n>0){
		if(n&1) ans=mul(ans,a);
		a=mul(a,a);
		n>>=1;
	}
	return ans;
}

int main(){
	ll x0,x1,a,b;
	scanf("%lld%lld%lld%lld",&x0,&x1,&a,&b);
	scanf("%s%lld",s,&mod);
	int len=strlen(s);
	mat ans,p;
	ans.init();
	p.a[0][0]=a;p.a[0][1]=b;
	p.a[1][0]=1;p.a[1][1]=0;
	for(int i=len-1;i>=0;i--){
		ans=mul(ans,poww(p,s[i]-'0'));//例：123，先是3次，然后23次，然后123次 
		p=poww(p,10);  //按位拆分 
	}
	//cout<<ans.a[1][0]<<endl;
	mat base;
	base.a[0][0]=x1;
	base.a[1][0]=x0;
	base=mul(ans,base);
	printf("%lld\n",base.a[1][0]);
	return 0;
}
