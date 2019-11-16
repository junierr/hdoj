#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int f[105][105],sum[105],a[105];

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		memset(f,0,sizeof(f));
		for(int i=0;i<=n;i++)
		  for(int j=i;j<=n;j++)
		    f[i][j]=inf;
		for(int i=0;i<=n;i++)
		  f[i][i]=0;
		for(int i=2;i<=n;i++){
			for(int l=1;l<=n-i+1;l++){
				int r=l+i-1;
				for(int k=l;k<=r;k++){
					f[l][r]=min(f[l][r],f[l+1][k]+f[k+1][r]+a[l]*(k-l)+(sum[r]-sum[k])*(k-l+1));
				}
			}
		}    
		printf("Case #%d: %d\n",t,f[1][n]);  
	}
	return 0;
}
