/*
一个起点流到药水和体力，然后再流 
起点0,勇士1-50，怪兽51-100，体力101，药水102，终点103 
*/

#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f 
using namespace std;

queue<int>dd;

char s[55][55];
int map[105][105];
int dis[105];


bool bfs()
{
    int i;
    dd=queue<int>();
    memset(dis,-1,sizeof(dis));
    dis[0]=0;
    dd.push(0);
    while(!dd.empty())
    {
        int cur=dd.front();
        dd.pop();
        for(i=0;i<=103;i++)
        {
            if(map[cur][i]&&dis[i]==-1)
            {
                dis[i]=dis[cur]+1;
                dd.push(i);
            }
        }
    }
    if(dis[103]>0) return 1;
    else return 0;
}

int dfs(int point,int maxx)
{
    int a,i;
    if(point==103) return maxx;
    for(i=0;i<=103;i++)
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


int main(){
	int T,n,m,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++){ 
			scanf("%s",s[i]);
			for(int j=0;j<m;j++){   
				if(s[i][j]=='1'){
					map[i+1][j+51]=1;  //勇士到怪兽 
				}
			}
		}
			map[0][101]=n;
			map[0][102]=k;
			for(int i=51;i<51+m;i++)
			  map[i][103]=1;      //怪兽到终点 
			for(int i=1;i<1+n;i++){  //药水和体力到勇士 
				map[101][i]=1;
				map[102][i]=1;
			}
		int ans=0;
        while(bfs())
        {
            int a=dfs(0,INF);
            ans+=a;
        }
		printf("%d\n",ans); 
	}
	return 0;
} 
