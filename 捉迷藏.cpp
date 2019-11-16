#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

bool vis[200005];
int dis[200005];
int head[200005];
int cnt,room,len,ans;

struct pp
{
	int y,next;
}edge[500005];//路径 

void add(int x,int y)
{
	edge[cnt].y=y;//这条路径通向Y点 
	edge[cnt].next=head[x];//上一条同一起点边的编号 
	head[x]=cnt++; //最后一条以x为起点边的编号 
}

void bfs()
{
	queue<int>dd;
	vis[1]=1;
	dd.push(1);
	room=1;
	len=0;
	ans=0;
	dis[1]=0;
	while(!dd.empty())
	{
		int cur=dd.front();
		dd.pop();
		for(int i=head[cur];i!=-1;i=edge[i].next)
		{
			if(vis[edge[i].y]==0)
			{
				vis[edge[i].y]=1;
				dd.push(edge[i].y);
				dis[edge[i].y]=dis[cur]+1;
				if(len<dis[edge[i].y])
				{
					len=dis[edge[i].y];
					room=edge[i].y;
					ans=1;
				}
				else if(len==dis[edge[i].y])
				{
					if(room>=edge[i].y)
					{
						room=edge[i].y;
					}
					ans++;
				}
			}
		}
	}
	
}

int main()
{
	int n,m,a,b,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		vis[i]=0;
	}
	cnt=0;
	memset(head,-1,sizeof(head)); 
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	bfs();
	printf("%d %d %d\n",room,len,ans);
	return 0; 
 } 
