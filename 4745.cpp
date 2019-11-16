#include<bits/stdc++.h>
using namespace std;

const int maxn=2005;
int a[maxn],b[maxn],f[maxn][maxn];


int main(){
	int  n;
	while(~scanf("%d",&n)){
		if(n==0) break;
		int ans=0;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i+n]=a[i];
		}
		for(int i=1;i<=2*n;i++)
		  f[i][i]=1;
		for(int i=1;i<=2*n;i++)
		  if(a[i]==a[i+1]) f[i][i+1]=2;
		  else f[i][i+1]=1;  
		for(int i=2;i<=2*n;i++){
			for(int l=1;l<=2*n-i+1;l++){
				int r=l+i-1;
				if(a[l]==a[r]) f[l][r]=max(f[l][r],f[l+1][r-1]+2);
				else f[l][r]=max(f[l][r-1],f[l+1][r]);
			}
		}
		for(int i=1;i<=n+1;i++){
			ans=max(ans,f[i][i+n-1]);
			ans=max(ans,f[i][i+n-2]+1);
		} 
		printf("%d\n",ans); 
	}
	return 0;
}
