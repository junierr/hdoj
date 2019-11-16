#include<cstdio>
#include<queue>
using namespace std;
int n,m;
int a[105][105];
int v[105][105];
int dict[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
struct pp
{
	int x;
	int y;
	int time;
	int step1;
	int step2;
};

void bfs(int x1,int y1,int x2,int y2)
{
	int i,j;
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    v[i][j]=9999;
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.x=x1;
	cur.y=y1;
	cur.time=6;
	cur.step1=0;
	cur.step2=0;
	d.push(cur);
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if(cur.x==x2&&cur.y==y2&&cur.time>0)
		{
			printf("%d\n",cur.step1);
			return;
		}
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			next.time=cur.time-1;
			if(next.time==0) continue;
			next.step1=cur.step1+1;
			next.step2=cur.step2+1;
			if(next.step2<v[next.x][next.y])
			{
			  v[next.x][next.y]=next.step2;
			  if(a[next.x][next.y]==1||a[next.x][next.y]==3)
			  {
				 d.push(next);
			  }
			  if(a[next.x][next.y]==4)
			  {
			  	next.time=6;
			  	next.step2=0;
			  	 d.push(next);
			  } 
		    }
		}    
	}
	printf("-1\n");
	return;
}


int main()
{
	int i,j,t,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++)
		  {
			scanf("%d",&a[i][j]);
		    if(a[i][j]==2) 
		    {
		    	x1=i;y1=j;
			}
			if(a[i][j]==3)
			{
				x2=i;y2=j;
			}
		  }
		bfs(x1,y1,x2,y2);
	}
	return 0;
} 
