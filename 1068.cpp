#include<cstdio>
#include<cstring>
using namespace std;

int map[1005][1005],mat[1005],vis[1005];
int t;

bool dfs(int x)
{
	int i;
	for(i=0;i<t;i++)
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
	int x,id,k,i;
	while(~scanf("%d",&t))
	{
		memset(mat,0,sizeof(mat));
		memset(map,0,sizeof(map));
		for(i=0;i<t;i++)
		{
			scanf("%d: (%d)",&id,&k);
			while(k--)
			{
				scanf("%d",&x);
				map[id][x]=1;
			}
		}
		int ans=0;
		for(i=0;i<t;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		printf("%d\n",t-ans/2);
	}
	return 0;
}
