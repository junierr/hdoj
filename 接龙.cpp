#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string> 
using namespace std;

char tr[30][30];
char ch[2];
int vis[30];
int an=0;
int ans=-1;
int n;
int pre[30][30];

int qq(int x,int y){  //返回x单词后连接一个y单词的最小重叠部分 
	bool pp=true;
	int ky=0;
	for(int k=strlen(tr[x])-1;k>=0;k--){
		for(int kx=k;kx<strlen(tr[x]);kx++){
			if(tr[x][kx]!=tr[y][ky++]){
				pp=false;
				break;
			}
		}
		if(pp==true) 
		  return strlen(tr[x])-k;
		ky=0;
		pp=true;  
	}
	return 0;
}

void dfs(int p){
	for(int j=1;j<=n;j++){
		if(vis[j]>=2) continue;
		if(pre[p][j]==0) continue;
		if((pre[p][j]==strlen(tr[p]))||(pre[p][j]==strlen(tr[j])))
		  continue;
		an+=strlen(tr[j])-pre[p][j];
		vis[j]++;
		dfs(j);
		an-=strlen(tr[j])-pre[p][j];
		vis[j]--;  
	}
	  ans=max(ans,an);
	return;  	
}


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%s",tr[i]);
	scanf("%s",ch); 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    pre[i][j]=qq(i,j); 
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(tr[i][0]==ch[0]){
			vis[i]++;
			an=strlen(tr[i]);
			dfs(i);
			vis[i]=0;
		}
	}
	printf("%d\n",ans);
	return 0;    
} 
