#include<cstdio>
#include<cstring>
using namespace std;

int map[105][105];
int path[105][105];
int n,m,t;

void dd()
{
	int i,j,max,next,k;
	int d[105];
	int road[105];
	for(i=1;i<=n;i++)
	{
		d[i]=map[1][i];
	}
	for(i=1;i<=n+1;i++)
	  for(j=1;j<=n+1;j++)
	    for(k=1;k<=n+1;k++)
	    {
	    	if(map[i][j]!= -1&&map[j][k]!=-1&&map[i][k]<map[i][j]+map[j][k])
	    	{
	    		map[i][k]=map[i][j]+map[j][k];
	    		path[i][k]=path[i][j];
			}
		}
	printf("points : %d\n",map[1][n+1]);
	printf("circuit : ");
	int s=1;
	while(s!=n+1)
	{
		printf("%d->",s);
		s=path[s][n+1];
	}
	printf("1\n");
	if(t!=0) printf("\n");
}

int main()
{
	int i,j,a,b,tmp=1;
	int city[105];
	scanf("%d",&t);
	while(t--)
	{
		memset(map,-1,sizeof(map));
        memset(path,0,sizeof(path));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&city[i]);
		}
		city[n+1]=0;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=city[b];
			path[a][b]=b;
		}
		printf("CASE %d#\n",tmp++);
		dd(); 
	}
	return 0;
}
