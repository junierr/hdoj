#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
char map[25][25];
int v[25][25];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int m,n,x1,y1;
struct pp
{
	int x;
	int y;
	int step;
};
int check(pp next)
{
		if(next.x<1||next.x>m||next.y<1||next.y>n) return 0;
		if(map[next.x][next.y]=='*') return 0;
		if(v[next.x][next.y]==1) return 0;
		return 1;
}


void bfs()
{
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.x=x1;
	cur.y=y1;
	cur.step=0;
	d.push(cur);
	v[x1][y1]=1;
	while(!d.empty())
	{
		int i;
		cur=d.front();
		d.pop();
		if(map[cur.x][cur.y]=='T')
		{
			printf("%d\n",cur.step);
			return;
		}
		for(i = 0; i < 4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if(check(next)==0) continue;
			else if (map[next.x][next.y] =='.'||map[next.x][next.y]=='T')
			{
				next.step=cur.step+1;
				d.push(next);
				v[next.x][next.y]=1;
			}
			else
			{
				if (i == 0 || i == 1)
				{
					if (map[next.x][next.y] == '|'&&cur.step % 2 == 1)
					{
						next.x = next.x + dir[i][0];
						next.y = next.y + dir[i][1];
						if (check(next)==1)
						{
							next.step = cur.step + 1;
							d.push(next);
							v[next.x][next.y] = 1;
						}
					}
					else if (map[next.x][next.y] == '-'&&cur.step % 2 == 0)
					{
						next.x = next.x + dir[i][0];
						next.y = next.y + dir[i][1];
						if (check(next)==1)
						{
							next.step = cur.step + 1;
							d.push(next);
							v[next.x][next.y] = 1;
						}
					}
					else
					{
						next.x = cur.x;
						next.y = cur.y;
						next.step = cur.step + 1;
						v[next.x][next.y] = 1;
						d.push(next);
					}

				}
				else if (i == 2 || i == 3)
				{
					if (map[next.x][next.y] == '|'&&cur.step % 2 == 0)
					{
						next.x = next.x + dir[i][0];
						next.y = next.y + dir[i][1];
						if (check(next)==1)
						{
							next.step = cur.step + 1;
							d.push(next);
							v[next.x][next.y] = 1;
						}
					}
					else if (map[next.x][next.y] == '-'&&cur.step % 2 == 1)
					{
						next.x = next.x + dir[i][0];
						next.y = next.y + dir[i][1];
						if (check(next)==1)
						{
							next.step = cur.step + 1;
							d.push(next);
							v[next.x][next.y] = 1;
						}
					}
					else
					{
						next.x = cur.x;
						next.y = cur.y;
						next.step = cur.step + 1;
						v[next.x][next.y] = 1;
						d.push(next);
					}
				}

			}
	}
}
    return;
}




int main()
{
	int i,j;
	while(cin>>m>>n)
	{
		for(i=1;i<=m;i++)
		  for(j=1;j<=n;j++)
		  {
		  	  cin>>map[i][j];
		  	  v[i][j]=0;
		  	  if(map[i][j]=='S')
		  	  {
		  	  	x1=i;y1=j;
			  }
		  }
		bfs();  
	}
	return 0;
}
