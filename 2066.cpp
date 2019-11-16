#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int>want;
int map[1005][1005];
int v[1005];
int city[1005];
int t,s,d;

int dd(int x)
{
	int i,j,k,next=x,min;
	int d[1005];
	memset(v,0,sizeof(v));  	
	for(i=1;i<=1000;i++)
	  d[i]=map[x][i];
	v[x]=1;
	for(i=1;i<=1000;i++)
	{
		min=99999;
		for(j=1;j<=1000;j++)
		{
			if(v[j]==0&&min>d[j])
			{
				min=d[j];
				next=j;
			}
		}
		v[next]=1;
		for(j=1;j<=1000;j++)
		{
			if(v[j]==0&&d[j]>d[next]+map[next][j])
			  d[j]=d[next]+map[next][j]; 
		}
	}
	int minxx=99999;
	for(i=1;i<=1000;i++)
	{
		if(want.count(i)==1&&minxx>d[i])
		{
			minxx=d[i];
		}
	}
	return minxx;  
} 



int main()
{
	int i,j,a,b,time,x;
	while(~scanf("%d%d%d",&t,&s,&d))
	{
		for(i=1;i<=1000;i++)
		  for(j=1;j<=1000;j++)
		  {
		  	if(i==j) map[i][j]=0;
		  	else map[i][j]=99999;
		  }	
		for(i=1;i<=t;i++)
		{
			scanf("%d%d%d",&a,&b,&time);
			if(time<map[a][b]||time<map[b][a])
			  map[a][b]=map[b][a]=time;			
		}
		want.clear();
		for(i=1;i<=s;i++)
		{
			scanf("%d",&city[i]);
		}
		for(i=1;i<=d;i++)
		{
			scanf("%d",&x);
			want.insert(x);
		}
		int min=99999; int now;
		for(i=1;i<=s;i++)
		{
			now=dd(city[i]);
			if(min>now) min=now;
		}
		printf("%d\n",min);
	}
	return 0;
 } 
