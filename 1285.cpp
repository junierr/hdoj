#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int map[505][505];
int indegree[505];
int dui[505];
int n;

void tuopu(){
    int top,i,j;
    int k=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(indegree[j]==0)
            {
                top=j;
                break;
            }
        }
        dui[k++]=top;
        indegree[top]=-1;
        for(j=1;j<=n;j++){
            if(map[top][j])
              indegree[j]--;
        }
    }
    for(i=0;i<n-1;i++){
        printf("%d ",dui[i]);
    }
    printf("%d\n",dui[n-1]);
}


int main(){
    int m,x,y;
    while(~scanf("%d%d",&n,&m)){
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        while(m--){
            scanf("%d%d",&x,&y);
            if(map[x][y])
              continue;
            map[x][y]=1;
            indegree[y]++;  
        }
    tuopu();    
    } 
}
