#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int mod=10007;
char s[200005];
int f[200005];

void make_f(){
	f[0]=0;
	int len=0,i=1;
	while(i<n){
		if(s[i]==s[len]){
			len++;
			f[i]=len;
			i++;
		}
		else{
			if(len>0){
				len=f[len-1];
			}
			else{
				f[i]=0;
                i++;
			}
		}
	}
	for(i=n;i>0;i--)
	  f[i]=f[i-1];
	f[0]=-1;  
} 

void dp(){
	int ans=n%mod;
	for(int i=n;;i=i-f[i]){ //每次找到一段区间前的0 
		while(f[i]<=0)
		  --i;
		if(i<=0)
		  break;
		ans=ans%mod+f[i]%mod;    
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s);
		make_f();
		dp(); 
	}
	return 0;
} 
