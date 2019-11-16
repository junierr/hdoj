#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cost[105][105];
int n,m;

void dd()
{
	int i,j,min,next=1;
	int v[105],d[105];
	for(i=1;i<=n;i++)
	{
		d[i]=cost[1][i];
		v[i]=0;
	}
	v[1]=1;
	for(i=1;i<=n;i++)
	{
		min=99999;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0&&min>d[j])
			{
				next=j;
				min=d[j];
			}
		}
		v[next]=1;
		for(j=1;j<=n;j++)
		{
			if(d[j]>d[next]+cost[next][j])
			{
				d[j]=d[next]+cost[next][j];
			}
		}
	}
	printf("%d\n",d[n]);
	return;
}


int main()
{
	int i,j,a,c,b;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	if(i==j)
		  	{
		  		cost[i][j]=cost[j][i]=0;
			}
			else 
			{
				cost[i][j]=cost[j][i]=99999;
			}
		  }
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c<cost[a][b])
			{
				cost[a][b]=cost[b][a]=c;
			}
		}
		dd();
	}
	return 0;
} 
