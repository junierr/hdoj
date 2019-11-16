#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char map[10][10];
int vis[20],may[20],maxx[20],map2[20][20],mapx[20][20],mapy[20][20];
int n,cnt1,cnt2;

void build()  //缩点 
//先扫描行，连通的格子看成一个结点，这样可以得到二分图的X部，再同样扫描列，得到Y部，有公共方格的结点连边，然后求最大匹配就是结果。

{
	int i,j;
	cnt1=0;cnt2=0;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
	  	if(map[i][j]=='.')
		  {
		  	if(j==0||map[i][j-1]!='.') cnt1++;
		  	mapx[i][j]=cnt1;
		   } 
	  }
	for(j=0;j<n;j++)
	  for(i=0;i<n;i++)
	  {
	  	if(map[i][j]=='.')
		  {
		  	if(i==0||map[i-1][j]!='.') cnt2++;
		  	mapy[i][j]=cnt2;
		   } 
	  }
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
	  	if(map[i][j]=='.') map2[mapx[i][j]][mapy[i][j]]=1; 
	  }
	return;       
} 

bool dfs(int x)
{
	int i;
	for(i=1;i<=cnt2;i++)
	{
		if(map2[x][i]&&!vis[i])
		{
			vis[i]=1;
			if(may[i]==0)
			{
				may[i]=x;
				maxx[x]=i;
				return 1;
			}
			else if(dfs(may[i]))
			{
				may[i]=x;
				maxx[x]=i;
				return 1;
			}
		 } 
	}
	return 0;
} 

int main()
{
	int i,j;
	while(cin>>n&&n)
	{
		memset(map,0,sizeof(map));
		memset(map2,0,sizeof(map2)); 
		memset(mapx,0,sizeof(mapx));
		memset(mapy,0,sizeof(mapy)); 
		memset(maxx,0,sizeof(maxx));
		memset(may,0,sizeof(may));
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		  {
		  	cin>>map[i][j];
		  }
		build(); 
		int ans=0;  
		for(i=1;i<=cnt1;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans);  
	}
	return 0;
}
