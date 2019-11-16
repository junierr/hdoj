#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
set<int> dd;

int map[105][105],map2[105][105],vis[105],mat[105];
int n;

bool dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(map2[x][i]&&!vis[i])
		{
			vis[i]=1;
			if(mat[i]==0)
			{
				mat[i]=x;
				return 1;
			}
			else if(dfs(mat[i]))
			{
				mat[i]=x;
				return 1;
			}
		}
	}
	return 0;
}


int main()
{
	int k,i,j,l,t;
	int v[10005],r[10005];
	while(~scanf("%d%d",&n,&k)&&n&&k)
	{
		dd.clear();
		t=0;
		memset(v,0,sizeof(v));
		memset(r,0,sizeof(r));
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	scanf("%d",&map[i][j]);
		  	if(dd.find(map[i][j])==dd.end())
			{
			  dd.insert(map[i][j]);
		      v[t++]=map[i][j];
			}
		  }
		sort(v,v+t);
		int sum=0;  
		for(i=0;i<t;i++)
		{
			memset(map2,0,sizeof(map2));
			memset(mat,0,sizeof(mat));
			for(j=1;j<=n;j++)
			  for(l=1;l<=n;l++)
			  {
			  	if(map[j][l]==v[i])
			  	{
			  		map2[j][l]=1;
				}
			  }
			int ans=0;
			for(j=1;j<=n;j++)
			{
				memset(vis,0,sizeof(vis));
				if(dfs(j)) ans++;
			}
			if(ans>k) 
			{
				r[sum++]=v[i];
			}  
		}
		if(sum==0) printf("-1\n");
		else 
		{
		  for(i=0;i<sum-1;i++)
	        printf("%d ",r[i]);
	      printf("%d\n",r[sum-1]);  
		}
		 
	}
	return 0;
 } 
