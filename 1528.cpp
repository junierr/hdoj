#include<cstdio>
#include<cstring>
using namespace std;

int k;
int map[30][30],mat[30],vis[30];
char zhi[15]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char hua[5]={'C','D','S','H'};
bool bigger(char b[],char a[])
{
	int x1,x2,i,j,y1,y2;
	for(i=0;i<13;i++)
	{
		if(b[0]==zhi[i]) x1=i;
		if(a[0]==zhi[i]) x2=i;
	}
	if(x1>x2) return 1;
	else if(x1==x2)
	{
		for(i=0;i<4;i++)
		{
			if(b[1]==hua[i]) y1=i;
			if(a[1]==hua[i]) y2=i; 
		}
		if(y1>y2) return 1;
	}
	return 0;
}

bool dfs(int x)
{
	int i;
	for(i=1;i<=k;i++)
	{
		if(map[x][i]&&!vis[i])
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
	int T;
	int i,j;
	char a[30][30],x[30][30];
	scanf("%d",&T); 
	while(T--)
	{
		scanf("%d",&k);
		for(i=1;i<=k;i++) scanf("%s",a[i]);
		for(i=1;i<=k;i++) scanf("%s",x[i]); 
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat)); 
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(bigger(x[i],a[j])) //x[i]>a[j]
	              map[i][j]=1;			
			}
		}
		int ans=0;
		for(i=1;i<=k;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++; 
		}
		printf("%d\n",ans);  
	}
	return 0;
}
