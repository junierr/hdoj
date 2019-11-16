/*
2sat
关键是建图
同一队i,j(任意i,j  i->非j连边,j->非i连边)
对队长关系,任意x,y(非x->y连边,非y->x连边) 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
#include<vector> 
using namespace std;

int dfn[4005],low[4005],scc[4005];
bool insta[4005];
int sta[4005];
vector<int> edge[4005];
int dfs_clock,top,scc_clock;
int n,k,m;
int cnt[4005];
int r[2005][2005];


void tarjan(int u){
	dfn[u]=low[u]=++dfs_clock;//标记时间戳
	sta[++top]=u;//入栈 
	insta[u]=true;//标记在栈里 
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(dfn[v]){
			if(insta[v])
			  low[u]=min(low[u],dfn[v]);
		}
		else {
		  tarjan(v);
	      low[u]=min(low[u],low[v]);
		}
	}
		if(dfn[u]==low[u]){
			++scc_clock;
			do{
				scc[u]=scc_clock;
				u=sta[top--];
				insta[u]=false;
			}while(low[u]!=dfn[u]);
		}	
}

bool sat(){
	for(int i=1;i<=2*n;i++)
	  if(!dfn[i]) tarjan(i);
    for(int i=0;i<k;i++){
    	for(int j=0;j<cnt[i];j++){
    	  		if(scc[r[i][j]]==scc[r[i][j]+n])
    	  		  return false;
		} 
	}
	return true;
} 


int main(){
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<2*n+1;i++)
		  edge[i].clear();
		while(m--){
			scanf("%d%d",&x,&y);
			edge[x+n].push_back(y);
			edge[y+n].push_back(x);
		}
		for(int i=0;i<k;i++){
			scanf("%d",&cnt[i]);
			for(int j=0;j<cnt[i];j++)
			  scanf("%d",&r[i][j]);
			for(int j=0;j<cnt[i];j++){
				for(int l=j+1;l<cnt[i];l++){
					if(r[i][j]!=r[i][l]){
						edge[r[i][j]].push_back(r[i][l]+n);
						edge[r[i][l]].push_back(r[i][j]+n);
					}
				}
			}
		}
		for(int i=0;i<4005;i++){
			dfn[i]=0;
			insta[i]=false;
			sta[i]=0;
		}
		dfs_clock=0;
		top=0;
		scc_clock=0;
		bool flag=sat();
		if(flag) printf("Yes\n");
		else printf("No\n");	  
	}
	return 0;
} 
