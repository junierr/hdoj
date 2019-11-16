#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int map[105][105];
int id[105],dp[10005];
int n,sum;
struct pp
{
	int x;
	int y;
}d[105];

int cmp(pp a,pp b)
{
	return a.x<b.x;
}
void dd()
{
	int v[105];
	int i,j,next=0,min,flag;
	for(i=1;i<=n;i++)
	{
		d[i].x=99999;
		v[i]=0;
	}
	d[0].x=0;d[0].y=0;
	v[0]=1;
	for(i=1;i<=n;i++)
	{
		min=99999;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0&&min>d[j].x)
			{
				min=d[j].x;
				next=j;
			} 
		}
		v[next]=1;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0&&d[j].x>d[next].x+map[next][j])
			{
				d[j].x=d[next].x+map[next][j];
			}
		}
	}

}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,i,j,st,ed,dis;
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		  for(j=0;j<=n;j++)
		  {
		  	if(i==j) map[i][j]=0;
		  	else map[i][j]=99999;
		  }
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&st,&ed,&dis);
			if(dis<map[st][ed]||dis<map[ed][st])
			  map[st][ed]=map[ed][st]=dis;
		}
		id[0]=0;
		sum=0;
		for(i=1;i<=n;i++)
		  {
		    scanf("%d",&id[i]);
		    d[i].y=id[i];
		    sum+=id[i];
		  }
		dd();
		memset(dp,0,sizeof(dp));
		int sum2=0;
		for(i=0;i<=n;i++)
		  if(d[i].x!=99999) sum2+=d[i].x;
		for(i=1;i<=n;i++)
		{
			for(j=sum2;j>=d[i].x;j--)
			{
				if(dp[j]<dp[j-d[i].x]+d[i].y)
				  dp[j]=dp[j-d[i].x]+d[i].y;
			}
		}
		for(i=0;i<=sum2;i++)
		{
			if(dp[i]>sum/2)
			  break; 
		}
		if(i==sum2+1) printf("impossible\n");
		else printf("%d\n",i);  
	}
	return 0;
} 
