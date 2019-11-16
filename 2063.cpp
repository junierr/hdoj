#include<cstdio>
#include<cstring>
using namespace std;
int map[505][505];
int mat[505];
int vis[505];

int n,m;

bool dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(map[x][i]&&!vis[i])
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
	int ans,k,i,a,b;
	while(~scanf("%d",&k)&&k)
	{
		scanf("%d%d",&m,&n);
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat)); 
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		ans=0;
		for(i=1;i<=m;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
