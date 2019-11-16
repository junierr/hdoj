#include<cstdio>
#include<cstring>
using namespace std;
int n;
int map[200][200],vis[200],mat[200];
bool dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&map[x][i])
		{
			vis[i]=1;
			if(!mat[i])
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
	int T,m,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
 } 
