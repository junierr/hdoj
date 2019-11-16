#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int v[25][25][1<<11];
char map[25][25];
struct pp
{
	int x;
	int y;
	int step;
	int key;
};
int m,n,t,x1,y1;
void bfs()
{
	int i;
	memset(v,0,sizeof(v));
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.x=x1;
	cur.y=y1;
	cur.step=0;
	cur.key=0;
	d.push(cur);
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if(map[cur.x][cur.y]=='^')
		{
			printf("%d\n",cur.step);
			return;
		}
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];
			next.step=cur.step+1;
			next.key=cur.key;
			if(next.x<1||next.x>n||next.y<1||next.y>m) continue;
			if(map[next.x][next.y]=='*'||next.step>=t) continue;
			if(map[next.x][next.y]>='a'&&map[next.x][next.y]<='z')
			  next.key=next.key|(1<<(map[next.x][next.y]-'a'+1));
			if(v[next.x][next.y][next.key]==0)
			{
				v[next.x][next.y][next.key]=1;
				if(map[next.x][next.y]>='A'&&map[next.x][next.y]<='Z')
				{
					if(next.key&(1<<(map[next.x][next.y]-'A'+1)))
					{
						d.push(next);
					}
				}
				else d.push(next);
			}  
		}
	}
	printf("-1\n");
	return;
}
int main()
{
	int i,j;
	while(cin>>n>>m>>t)
	{
		for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++)
		  {
		  	cin>>map[i][j];
		  	if(map[i][j]=='@')
		  	{
		  		x1=i;y1=j;
			}
		
			
		  }
	    bfs();	  
	}
	return 0;
} 
