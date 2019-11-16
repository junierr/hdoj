#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int map[205][205];
int n,m;

void dd(int s,int t)
{
	int v[205],next=s,d[205],i,j,min;
	for(i=0;i<n;i++)
	{
		d[i]=map[s][i];
		v[i]=0;
	}
	v[s]=1;
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
	if(d[t]==99999) printf("-1\n");
	else printf("%d\n",d[t]);
	return;
}

int main()
{
    int i,j,s,t,a,b,c;
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
			scanf("%d%d%d",&a,&b,&c);
			if(c<map[a][b])
			{
				map[a][b]=map[b][a]=c;
			}
		}
		scanf("%d%d",&s,&t);
		dd(s,t); 
	}
	return 0;
}
