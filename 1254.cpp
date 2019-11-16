#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int map[10][10];
int v1[10][10][10][10];
int v2[10][10];
int dict[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int m,n,x1,y1,xr,yr;
struct pp
{
	int x,y;
	int xr,yr;
	int step;
};
struct asdas
{
	int x,y;
}ren,person;

int bfs1(asdas person)
{
	int i;
	queue<asdas>p;
	p=queue<asdas>();
	asdas cur,next;
	p.push(person);
	v2[person.x][person.y]=1;
	while(!p.empty())
	{
		cur=p.front();
		p.pop();
		if(cur.x==ren.x&&cur.y==ren.y)
		  return 1;
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			if(next.x>m||next.x<=0||next.y>n||next.y<=0) continue;
			if(map[next.x][next.y]==1) continue;
			if(next.x==x1&&next.y==y1) continue;
			if(v2[next.x][next.y]==1) continue;
			v2[next.x][next.y]=1;
			p.push(next);
		}  
	}
	return 0;
}


void bfs()
{
	int i;
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.x=x1;
	cur.y=y1;
	cur.xr=xr;
	cur.yr=yr;
	d.push(cur);
	v1[x1][y1][xr][yr]=1;
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if(map[cur.x][cur.y]==3)
		{
			printf("%d\n",cur.step);
			return;
		}
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			next.step=cur.step+1;
			next.xr=cur.x;
			next.yr=cur.y;
			ren.x=cur.x-dict[i][0];
			ren.y=cur.y-dict[i][1];
			if(next.x>m||next.x<=0||next.y>n||next.y<=0) continue;
			if(map[next.x][next.y]==1) continue;
			if(ren.x>m||ren.x<=0||ren.y>n||ren.y<=0) continue;
			if(map[ren.x][ren.y]==1) continue;
			if(v1[next.x][next.y][next.xr][next.yr]==1) continue;
			person.x=cur.xr;
			person.y=cur.yr;
			x1=cur.x;
			y1=cur.y;
			memset(v2,0,sizeof(v2));
			if(!bfs1(person)) continue;
			v1[next.x][next.y][next.xr][next.yr]=1;
			d.push(next);
		}
	}
	printf("-1\n");
	return;
}


int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		memset(v1,0,sizeof(v1));
		for(i=1;i<=m;i++)
		  for(j=1;j<=n;j++)
	      {
	      	scanf("%d",&map[i][j]);
	      	if(map[i][j]==2)
	      	{
	      		x1=i;y1=j;
			}
			if(map[i][j]==4)
			{
				xr=i;yr=j;
			}
		  }
		bfs();  
	}
	return 0;
} 
