#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int indegree[30005],que[30005];

vector<int>map[30005];
priority_queue<int,vector<int> >q;

void init(){
	for(int i=1;i<=n;i++)
	  map[i].clear();
	for(int i=1;i<=n;i++)
	  indegree[i]=0;  
}

void tuopu(){
	int k=0;
	for(int i=1;i<=n;i++)
	  if(indegree[i]==0)
	    q.push(i);
	while(!q.empty()){
		int v=q.top();
		que[k++]=v;
		q.pop();
		for(int j=0;j<map[v].size();j++){
			indegree[map[v][j]]--;
			if(indegree[map[v][j]]==0){
				q.push(map[v][j]);
			}
		}
	}
	for(int i=k-1;i>0;i--)
	  printf("%d ",que[i]);
	printf("%d\n",que[0]);      
}


int main(){
	int T,m,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			scanf("%d%d",&a,&b);
			map[b].push_back(a);
			indegree[a]++;
		}
		tuopu();
	}
	return 0;
}
