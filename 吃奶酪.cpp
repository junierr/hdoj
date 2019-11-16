#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n;
double ans;
struct pp{
	double x,y;
}a[20];

double dis[20][20];
int vis[20]={0};

void dfs(int now,double len){
	ans=INF;
	if(len<=ans)
	  return;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			len+=dis[now][i];
			dfs(i,len);
		}
		vis[i]=0;
	} 
	ans=min(ans,len); 
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	    dis[i][j]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
	vis[0]=1;
	dfs(0,0);
	printf("%.2f\n",ans);
	return 0;	  
} 
