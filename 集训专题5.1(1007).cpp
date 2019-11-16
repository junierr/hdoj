#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int map[130][130],all[130][130],some[130][130],none[130][130];
//map地图，all当前加入团的点集，some即将进行搜索的点集，none之后一步搜索不用的点集 
int s;

void dfs(int d,int an,int sn,int nn) 
//d当前节点，an当前已加入团的节点数，sn即将进行搜索的点集的节点数，nn之后一步搜索不用的点集的节点数
{
	int j,i;
	if(s>1000) return;
	if(sn==0&&nn==0) s++;
	int u=sn>0?some[d][0]:none[d][0];
	for(i=0;i<sn;i++)
	{
		int v=some[d][i];
		if(map[u][v]) continue;
		int tsn=0,tnn=0;
		for(j=0;j<an;j++)
          all[d+1][j]=all[d][j];
        all[d+1][an]=v;
		for(j=0;j<sn;j++)
		  if(map[v][some[d][j]])
		    some[d+1][tsn++]=some[d][j];
		for(j=0;j<nn;j++)
		  if(map[v][none[d][j]])
		    none[d+1][tnn++]=none[d][j];
		dfs(d+1,an+1,tsn,tnn);
		some[d][i]=0,none[d][nn++]=v;	    
	} 
} 




int main()
{
	int n,m,i,j,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map)); 
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;
		}
		s=0;
		memset(some,0,sizeof(some));
		for(i=0;i<n;i++) some[0][i]=i+1;
		memset(all,0,sizeof(all));
		memset(none,0,sizeof(0));
		dfs(0,0,n,0);
		if(s>1000) printf("Too many maximal sets of friends.\n");
		else printf("%d\n",s); 
	}
	return 0;
 } 
