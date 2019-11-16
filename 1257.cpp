#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct pp{
	int x,y;
}a[300005];

int vis[300005];

bool cmp(pp x,pp y){
	return x.x>y.x;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].x);
			a[i].y=i;
		}
		memset(vis,0,sizeof(vis));
		sort(a,a+n,cmp);
	    int cnt=0;
	    int ans=0;
	    int k=-1;
	    while(cnt!=n){
	    	ans++;
	    	k=-1;
	    	for(int i=0;i<n;i++){
	    		if(k==-1&&vis[i]==0){
	    			vis[i]=1;
	    			k=a[i].y;
	    			cnt++;
				}
				else if(k!=-1&&vis[i]==0){
					if(a[i].y>k){
						k=a[i].y;
						vis[i]=1;
						cnt++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
