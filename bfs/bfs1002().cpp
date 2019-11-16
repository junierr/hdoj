#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
using namespace std;
int map[1005][1005];
int cs[1005][1005];	
unsigned int direct[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m; 
struct node
{
 int x,y;
 int step,dir;
};

 void bfs(int x1,int y1,int x2,int y2)
 {
 int i,j;
  queue<node>q;
  q=queue<node>();
  node cur,next;
  cur.x=x1;cur.y=y1;
  cur.step=-1;cur.dir=-1;
  q.push(cur);
  for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	  cs[i][j]=3;
  while(!q.empty())
  {
     cur=q.front ();
	 q.pop();
	 for(i=0;i<4;i++)
	 {
         next.x=cur.x+direct[i][0];
		 next.y=cur.y+direct[i][1];
         next.step=cur.step;
		 next.dir=cur.dir;
		 if(next.dir!=i)
		 {
			 next.step++;
			 next.dir=i;
		 }
		 if(next.x==x2&&next.y==y2&&next.step<=2)
			{
				printf("YES\n");
				return ;
			}
		 if(next.step<3&&next.x>0&&next.x<=n&&next.y>0&&next.y<=m&&map[next.x][next.y]==0)
		 {
			 if(cs[next.x][next.y]>=next.step)  
            {  
                q.push(next); 
                cs[next.x][next.y]=next.step;    
            }
		 }

	 }
  }
   printf("NO\n");
 }

 int main()
 {
	 int q,i,j,x1,x2,y1,y2;
	 while(scanf("%d%d",&n,&m),n+m)
	 {
       for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
           scanf("%d",&map[i][j]);
	   scanf("%d",&q);
	   for(i=0;i<q;i++)
	   {
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		 if(map[x1][y1]==map[x2][y2]&&map[x1][y1]!=0)
		    bfs(x1,y1,x2,y2);
		 else
			 printf("NO\n");
	   }
	 }
   return 0;
 }
