#include<cstdio>
#include<cstring>
using namespace std;

int p,n;
int mat[305],vis[305],map[305][305];


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
	int T,i,j,k,q;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&p,&n);
		memset(mat,0,sizeof(mat));
		memset(map,0,sizeof(map));
		for(i=1;i<=p;i++)
		{
			scanf("%d",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&q);
				map[i][q]=1;
			} 
		}
		int ans=0;
		for(i=1;i<=p;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		if(ans==p) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
