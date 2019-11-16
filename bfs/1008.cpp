#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int dict[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[105][105];
int v[105][105];
int n,m,x1,x2,y1,y2,k;
struct pp
{
	int x;
	int y;
	int change;
	int dir;
};
queue<pp>d;


void bfs()
{
	int i;
	d=queue<pp>();
	pp cur,next;
	cur.x=x1;
	cur.y=y1;
	cur.change=-1;
	cur.dir=-1;
	v[x1][y1]=0;
	d.push(cur);
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if(cur.x==x2&&cur.y==y2&&cur.change<=k)
		{
			printf("yes\n");
			return;
		}
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			next.dir=i;
			if(next.dir!=cur.dir) next.change=cur.change+1;
			else next.change=cur.change;
			if(next.x>=n||next.x<0||next.y>=m||next.y<0) continue;
			if(next.change>k) continue;
			if(map[next.x][next.y]=='*') continue;
			if(next.change<=v[next.x][next.y])
			{
				v[next.x][next.y]=next.change;
				d.push(next);
			}
		}
	}
	printf("no\n");
	return;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		  {
		  	scanf("%s",map[i]) ;
		  }
		memset(v,9999,sizeof(v));
		scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);
		x1--;
		y1--;
		x2--;
		y2--;
		if(map[x1][y1]=='*'||map[x2][y2]=='*')
		{
			printf("no\n");
			continue;
		}
		if(x1==x2&&y1==y2)
		  {
			printf("yes\n");
			continue;
		  }
		bfs();  
	}
	return 0;
} 
