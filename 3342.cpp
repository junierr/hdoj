#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 105
using namespace std;

vector<int >a[N],ans;
int du[N];
int n;

void tobo(){
	int res=0;
	while(1){
		int tmp=-1;
		for(int i=0;i<n;i++){
			if(du[i]==0){
				tmp=i;
				break;
			}
		}
		if(tmp==-1) break;
		ans.push_back(tmp);
		res++;
		du[tmp]=-1;
		for(int i=0;i<a[tmp].size();i++)
		  du[a[tmp][i]]--;   
	}
	if(res==n) printf("YES\n");
	else printf("NO\n");
}



int main(){
	int m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0) break;
		for(int i=0;i<N;i++){
			a[i].clear();
			du[i]=0;
		}
		  
		ans.clear();  
		memset(du,0,sizeof(du));  
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].push_back(y);
			du[y]++;
		}
		tobo();
	}
	return 0;
} 
