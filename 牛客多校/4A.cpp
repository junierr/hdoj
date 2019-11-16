#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<vector> 
#include<map>
#define inf 0x3f3f3f3f
using namespace std;
/*
因为n个点只有n-1条边，所以是链式的，所以两遍bfs找距离最远的点d/2即可 
*/

vector<int> edg[100005];
set<int>p;
int vis[100005];
int q[100005];
struct pp{
	int x,step;
};
int cnt,k;

int bfs(int s,int t){
	queue<pp>que;
	while(!que.empty()) que.pop();
	vis[s]=1;
	pp cur,nex;
	cur.x=s;
	cur.step=0;
	que.push(cur);
	while(!que.empty()){
		cur=que.front();
		if(p.find(cur.x)!=p.end()) cnt++;
		que.pop();
		if(cnt==k&&t==0){
			return cur.x;
		}
		else if(cnt==k&&t==1){
			return cur.step;
		}
		for(int i=0;i<edg[cur.x].size();i++){
			if(vis[edg[cur.x][i]]==0){
				vis[edg[cur.x][i]]=1;
				nex.step=cur.step+1;
				nex.x=edg[cur.x][i];
				que.push(nex);
			}
		}
	}
}


int main(){
	int n;
	while(~scanf("%d%d",&n,&k)){
		for(int i=0;i<n+5;i++)
		  edg[i].clear();
		p.clear();  
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		for(int i=0;i<k;i++){
			scanf("%d",&q[i]);
			p.insert(q[i]);
		}
		memset(vis,0,sizeof(vis));
		cnt=0;
		int x=bfs(q[0],0);
		memset(vis,0,sizeof(vis));
		cnt=0;
		int ans=bfs(x,1);
		printf("%d\n",(ans+1)/2);
	}
	return 0;
} 
