#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


char s[100005];
int f[100005];

void makef(){
	f[0]=0;
	f[1]=0;
	int len=strlen(s);
	int k=0;
	for(int i=2;i<=len;i++){
		while(s[k]!=s[i-1]&&k){
			k=f[k];			
		}
		if(s[k]==s[i-1]) k++;
		f[i]=k; 
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		makef();
		int len=strlen(s);
		int circle=len-f[len];
		if(len%circle==0&&len/circle>=2)
		  printf("0\n");
		else 
		  printf("%d\n",circle-(len%circle));   
	}
	return 0;
} 
