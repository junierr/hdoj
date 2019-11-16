/*����ͼ��

ÿһ�����е�, �������� �������ҵĿ��е�����, ���͵õ���һ������ͼ, Ȼ��ֱ��

���ƥ��, �������������, ������͸��, �������ر�. �� ������, ��Ϊ���ڿ�֮����±�

�ʹ�����ż��ϵ, ����ֻȡ ż�� �� ������ ��ͼ������.
*/

#include<cstdio>
#include<cstring>
using namespace std;

int map[105][105],mat[105],vis[105],map2[105][105];
int n,m,cnt;
int dict[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int a[105][105]; 
struct pp
{
	int x,y;
}r[105];

void build()
{
	int i,j,l;
	cnt=1;
	memset(r,0,sizeof(r)); 
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	  {
	  	if(map[i][j]==0)
	  	{
	  		a[i][j]=cnt;
	  		r[cnt].x=i;
	  		r[cnt].y=j;
	  		cnt++;
		}
	  }
	memset(map2,0,sizeof(map2));
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    if(map[i][j]==0)
	      for(l=0;l<4;l++)
	      {
	      	int x=i+dict[l][0];
	      	int y=j+dict[l][1];
	      	if(x>=1&&x<=n&&y>=1&&y<=m)
	      	{
	      		map2[a[i][j]][a[x][y]]=1;
	      		map2[a[x][y]][a[i][j]]=1;
			}
		  }
	return;	  
}

bool dfs(int x)
{
	int i;
	for(i=1;i<cnt;i++)
	{
		if(map2[x][i]&&!vis[i])
		{
			vis[i]=1;
			if(mat[i]==0)
			{
				mat[i]=x;
				return 1;
			}
			else if(dfs(mat[i]))
			{
				mat[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i,k,x,y;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat)); 
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		build();
		int ans=0;
		for(i=1;i<cnt;i++)  
		{
			if((r[i].x+r[i].y)%2==1) continue; //ֻ��ż���� 
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		 } 
		 printf("%d\n",ans);
		 for(i=1;i<cnt;i++)
		 {
		 	if(mat[i])
		 	{
		 		printf("(%d,%d)--(%d,%d)\n",r[i].x,r[i].y,r[mat[i]].x,r[mat[i]].y);
			}
		 }
		 printf("\n");
	}
	return 0;
} 
