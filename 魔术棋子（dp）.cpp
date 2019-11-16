#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int map[105][105];
bool dp[105][105][105];
int a[105];

int main()
{
	int m,n,k,i,j,l;
	scanf("%d%d%d",&m,&n,&k);
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	    {
		  scanf("%d",&map[i][j]);
		  map[i][j]%=k;
	    }
	dp[1][1][map[1][1]]=1;
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	    for(l=0;l<k;l++)
		{
			if(dp[i][j][l*map[i][j]%k]==0)
			  dp[i][j][l*map[i][j]%k]=dp[i-1][j][l]||dp[i][j-1][l];	  
		}
	int ans=0;	
	for(i=0;i<k;i++)
	{
		if(dp[m][n][i]) 
		{
		  ans++;
	      a[ans]=i;
		}
	}
	printf("%d\n",ans);
	printf("%d",a[1]);
	for(i=2;i<=ans;i++)
	  printf(" %d",a[i]);
	printf("\n");
	return 0;  	   
 } 
