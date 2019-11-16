#include<cstdio>
#include<cstring>
using namespace std;
int map[105][105],mat[105],vis[105];
int n,m,k;

bool dfs(int x)
{
	int i;
	for(i=1;i<m;i++)
	{
		if(!vis[i]&&map[x][i])
		{
			vis[i]=1;
			if(mat[i]==-1)
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
	int id,x,y,i;
	while(~scanf("%d",&n)&&n)
	{
		scanf("%d%d",&m,&k);
		memset(map,0,sizeof(map));
		memset(mat,-1,sizeof(mat));
		for(i=1;i<=k;i++)
		{
			scanf("%d%d%d",&id,&x,&y);
			map[x][y]=1; 
		}
		int ans=0;
		for(i=1;i<n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
