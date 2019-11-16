#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<long long> dd;
long long map[205][205],dis[205];
long long m;


bool bfs()
{
	long long i;
	dd=queue<long long>();
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	dd.push(1);
	while(!dd.empty())
	{
		long long cur=dd.front();
		dd.pop();
		for(i=1;i<=m;i++)
		{
			if(map[cur][i]&&dis[i]==-1)
			{
				dis[i]=dis[cur]+1;
				dd.push(i);
			}
		}
	}
	if(dis[m]!=-1) return 1;
	else return 0;
}

long long dfs(long long point,long long maxx)
{
	long long a,i;
	if(point==m) return maxx;
	for(i=1;i<=m;i++)
	{
		if(map[point][i]&&dis[i]==dis[point]+1&&(a=dfs(i,min(maxx,map[point][i]))))
		{
			map[point][i]-=a;
			map[i][point]+=a;
			return a;
		}
	}
	return 0;
}

int main()
{
	long long n,c,s,e,i;
	while(~scanf("%lld%lld",&n,&m))
	{
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&c,&s,&e);
			map[c][s]+=e;
		}
		long long ans=0;
		while(bfs())
		{
			long long ss=dfs(1,999999999);
			ans+=ss;
		}
		printf("%lld\n",ans); 
	}
	return 0;
}
