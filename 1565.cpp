#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<int> dd;
int map[25][25],temp[405][405];
int dict[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n;

bool judge(int x,int y)
{
	if(x>0&&x<=n&&y>0&&y<=n)
	  return 1;
	else return 0;  
}

int bfs(int s,int t)
{
	int i;
	int flow=0;
	while(1)
	{
	  int minn=99999;
	  dd=queue<int>();
	  dd.push(s);
	  int dis[405];
	  memset(dis,-1,sizeof(dis));
	  while(!dd.empty())
	  {
	  	int cur=dd.front();
	  	dd.pop();
	  	for(i=1;i<=n*n+1;i++)
	  	{
	  		if(temp[cur][i]>0&&dis[i]==-1)
	  		{
	  			dd.push(i);
	  			if(temp[cur][i]<minn)
	  			  minn=temp[cur][i];
			    dis[i]=cur;
			}
		}
		if(dis[t]!=-1) break;
	   }
	   int u=t;
	   if(dis[u]<=0) break;
	   while(u!=s)
	   {
	   	 temp[dis[u]][u]-=minn;
	   	 temp[u][dis[u]]+=minn;
	   	 u=dis[u];
	   }
	   flow+=minn; 
    }
    return flow;
}



int main()
{
	int i,j,k;
	while(~scanf("%d",&n))
	{
		int sum=0;
		memset(map,0,sizeof(map));
		memset(temp,0,sizeof(temp));
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	scanf("%d",&map[i][j]);
		  	sum+=map[i][j];
		  }
		//假设0为源点，n*n+1为汇点；  
	    for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	if((i+j)%2==0) //源点与偶数相连 
		  	  temp[0][(i-1)*n+j]=map[i][j];
			else         //奇数与汇点相连 
			  temp[(i-1)*n+j][n*n+1]=map[i][j];	 
		  }  
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		    for(k=0;k<4;k++)
		    {
		    	int x=i+dict[k][0];
		    	int y=j+dict[k][1];
		    	if(judge(x,y)&&(i+j)%2==0)
		    	  temp[(i-1)*n+j][(x-1)*n+y]=99999;
			}	
		printf("%d\n",sum-bfs(0,n*n+1));    
	}
	return 0;
} 
