#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
using namespace std;
int dict[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[205][205];
int v[205][205];
int x1,y1,n,m;
struct pp
{
	int x;
	int y;
	int step;
};
void bfs()
{
	int i,j,sum=99999;
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.x=x1;
	cur.y=y1;
	cur.step=0;
	d.push(cur);
	v[x1][y1]=0;
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if(map[cur.x][cur.y]=='r'&&cur.step<sum) sum=cur.step;
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			if(next.x>n||next.x<1||next.y>m||next.y<1) continue;
			if(map[next.x][next.y]=='#') continue;
			if(map[next.x][next.y]=='.') next.step=cur.step+1;
			if(map[next.x][next.y]=='x') next.step=cur.step+2;
			if(map[next.x][next.y]=='r') next.step=cur.step+1;
			if(next.step>=v[next.x][next.y]) continue;
			d.push(next);
			v[next.x][next.y]=next.step;
		}
	}
	  if(sum==99999) printf("Poor ANGEL has to stay in the prison all his life.\n");
	  else printf("%d\n",sum);
	  return;
}


int main()
{
	int i,j;
	while(cin>>n>>m)
	{
		for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++)
		  {
		  	cin>>map[i][j];
		  	v[i][j]=99999;
		  	if(map[i][j]=='a') 
		  	{
		  		x1=i;
		  		y1=j;
		    }
		  }
		bfs();  
	}
	return 0;
}
