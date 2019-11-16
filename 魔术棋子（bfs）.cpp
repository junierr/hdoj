#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int dict[2][2]={{0,1},{1,0}};
int vis[105][105][105];
int map[105][105];
struct pp
{
  int x,y;
  int val;
};
int m,n,k;
int a[105];
void bfs()
{
	pp cur,next;
	queue<pp>dd;
	cur.x=1;
	cur.y=1;
	cur.val=map[1][1];
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	vis[1][1][map[1][1]]=1;
	dd.push(cur);
	while(!dd.empty())
	{
		cur=dd.front();
		dd.pop();
		for(int i=0;i<2;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			if(next.x>=1&&next.x<=m&&next.y>=1&&next.y<=n)
			{
				next.val=cur.val*map[next.x][next.y]%k;
				if(vis[next.x][next.y][next.val]==0)
				{
					dd.push(next);
					vis[next.x][next.y][next.val]=1;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<k;i++)
	{
		if(vis[m][n][i]) 
		{
		  ans++;
		  a[ans]=i;
	    }
	}
	printf("%d\n",ans);
	printf("%d",a[1]);
	for(int i=2;i<=ans;i++)
	  printf(" %d",a[i]);
	printf("\n");  
}

int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	    {
		  scanf("%d",&map[i][j]);
		  map[i][j]%=k;
	    }
	bfs();    
} 
