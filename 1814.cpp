#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int R=1;
const int B=2;
vector<int>map[20005];

int color[20005];
int temp[20005];
int num;
int n,m;

bool dfs(int u){
	if(color[u]==R)
	  return true;
	if(color[u]==B)
	  return false;
	color[u]=R;
	color[((u-1)^1)+1]=B;
	temp[num++]=u;  
	for(int i=0;i<map[u].size();i++){
		if(!dfs(map[u][i]))
		  return false;
	}
	return true;  
}

bool solve(){
	memset(color,0,sizeof(color));
	for(int i=1;i<=2*n;i++){
		if(color[i]==0){
			num=0;
			if(!dfs(i)){ //染色失败,之前的还原 
			for(int j=0;j<num;j++){
				color[temp[j]]=0;
				color[(temp[j]-1^1)+1]=0;	
			} 
			if(!dfs(((i-1)^1)+1)) //两个点都染色失败，无解 
			  return false;
		}
	}
}
	return true;
}


int main(){
	int a,b;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=2*n;i++)
		  map[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			map[a].push_back(((b-1)^1)+1); //放入可染色的 
			map[b].push_back(((a-1)^1)+1); 
		}
		if(solve()){
			for(int i=1;i<=2*n;i++)
			  if(color[i]==R)
			    printf("%d\n",i);
		}else{
			printf("NIE\n");
		}  
	}
	return 0; 
} 
