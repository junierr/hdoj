#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int v[1005];
	while(~scanf("%d",&n)){
		if(n==0) break;
		for(int i=1;i<=n;i++)
		  scanf("%d",&v[i]);
		int now=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(now<v[i]){
				ans+=(v[i]-now)*6;
				ans+=5;
				now=v[i];
			}
			else if(now>v[i]){
				ans+=(now-v[i])*4;
				ans+=5;
				now=v[i];
			}
			else{
				ans+=5;
			}
		}
		printf("%d\n",ans);  
	}
	return 0;
} 
