#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,cnt,last;
int head[100005],nextt[100005],v[100005],w[100005],depth[100005];

void _add(int u,int vi,int wi)
{
	cnt++;
	nextt[cnt]=head[u];
	v[cnt]=vi;
	w[cnt]=wi;
	head[u]=cnt;
}


void add_edge(int u,int vi,int wi)
{
	_add(u,vi,wi);
	_add(vi,u,0);
}

int dfs(int u,int dist)
{
	int i;
	if(u==last+n+1) return dist;
	for(i=head[u];i!=-1;i=nextt[i])
	{
		if(depth[v[i]]==depth[u]+1&&w[i]!=0)
		{
			int di=dfs(v[i],min(dist,w[i]));
			if(di>0)
			{
				w[i]-=di;
				w[i^1]+=di;
				return di;
			}
		}
	}
	return 0;
}

bool bfs()
{
	queue<int>dd;
	memset(depth,0,sizeof(depth));
	depth[0]=1;
	dd.push(0);
	while(!dd.empty())
	{
		int cur=dd.front();
		dd.pop();
		for(int i=head[cur];i!=-1;i=nextt[i])
		{
			if(w[i]>0&&depth[v[i]]==0)
			{
				depth[v[i]]=depth[cur]+1;
				dd.push(v[i]);
			}
		}
	 }
	 if(depth[last+n+1]==0) return 0;
	 return 1; 
}


int dinic()
{
	int ans=0;
	while(bfs())
	{
		while(int d=dfs(0,99999))
		  ans+=d;
	}
	return ans;
}

int main()
{
	int T,t,m,i,p,s,e;
	scanf("%d",&T);
	t=1;
	while(T--)
	{
		memset(head,-1,sizeof(head));
		memset(nextt,-1,sizeof(nextt));
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w)); 
		scanf("%d%d",&n,&m);
		cnt=0;
		int sum=0;
	    last=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p,&s,&e);
			sum+=p;
			last=max(e,last);
			add_edge(0,i,p);
			for(int j=s;j<=e;j++)
			  add_edge(i,n+j,1);	
		}
		for(i=n+1;i<=n+last;i++)
		{
			add_edge(i,last+n+1,m);
		}
		int ans=dinic();
		printf("Case %d: ",t++);
		if(ans==sum) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
