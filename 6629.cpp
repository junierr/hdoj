#include<bits/stdc++.h>
using namespace std;

char s[1000005];
int z[1000005];

void solve(){
	int len=strlen(s);
	int l=0,r=0;
	memset(z,0,sizeof(z));
	for(int i=1;i<len;i++){
		if(i<=r) z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<len&&s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	}
	long long sum=0;
	for(int i=1;i<len;i++){
		sum+=z[i];
		if(i+z[i]<len) sum++;
	}
	printf("%lld\n",sum);
}



int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%s",s);
	solve();
}
	return 0;
} 
