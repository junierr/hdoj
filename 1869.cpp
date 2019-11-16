#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int map[105][105];
int n,m;
int dd(int g)
{
	int i,j,d[105],v[105],min,next=g,max;
	for(i=0;i<n;i++)
	{
		d[i]=map[g][i];
		v[i]=0;
	}
	v[g]=1;
	for(i=0;i<n;i++)
	{
		min=99999;
		for(j=0;j<n;j++)
		{
			if(v[j]==0&&min>d[j])
			{
				min=d[j];
				next=j;
			}
		}
		v[next]=1;
		for(j=0;j<n;j++)
		{
			if(v[j]==0&&d[j]>d[next]+map[next][j])
			{
				d[j]=d[next]+map[next][j];
			}
		}	
	}
	max=0;
	for(i=0;i<n;i++)
	{
		if(max<d[i]) max=d[i];
	}
	return max;
}



int main()
{
	int i,j,a,b,max,now;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		  {
		  	if(i==j) map[i][j]=map[j][i]=0;
		  	else map[i][j]=map[j][i]=99999;
		  }
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(map[a][b]!=0)
			{
				map[a][b]=map[b][a]=1;
			}
		}
		max=0;
		for(i=0;i<n;i++) 
		{
			now=dd(i);
			if(max<now) max=now;
		}
		if(max>7) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
