#include<cstdio>
#include<queue>
using namespace std;
int map[55][55][55];
int dict[][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int v[55][55][55];
int a,b,c,t;
struct pp
{
	int x;
	int y;
	int z;
	int time;
};
void bfs()
{
	int i;
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.x=0;
	cur.y=0;
	cur.z=0;
	cur.time=t;
	d.push(cur);
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if(cur.x==a-1&&cur.y==b-1&&cur.z==c-1&&cur.time>=0)
		{
			printf("%d\n",t-cur.time);
			return;
		}
		for(i=0;i<6;i++)
		{
			next.x=cur.x+dict[i][0];
			next.y=cur.y+dict[i][1];
			next.z=cur.z+dict[i][2];
			next.time=cur.time-1;
			if(next.x<0||next.y<0||next.z<0||next.x>a-1||next.y>b-1||next.z>c-1)
			  continue;
			if(next.time>v[next.x][next.y][next.z])
			{
				if(map[next.x][next.y][next.z]==0)
				{
					d.push(next);
					v[next.x][next.y][next.z]=next.time;
				}
			}
		}
	}
	printf("-1\n");
	return;
}


int main()
{
	int k,i,j,l;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				for(l=0;l<c;l++)
				{
					scanf("%d",&map[i][j][l]);
					v[i][j][l]=0;
				}
			}
		}
		v[0][0][0]=t;
		if(map[a-1][b-1][c-1]==1) printf("-1\n");
		else bfs();
	}
	return 0;
} 
