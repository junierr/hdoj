#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[55][55];
int v[55];
int n,bestn,cn;

int check(int x)
{
	int i;
	for(i=1;i<x;i++)
	  if(v[i]&&a[x][i]==0) return 0;
	return 1;  
}
void dfs(int x)
{
	if(x>n)
	{
		bestn=max(cn,bestn);
		return;
	}
	if(check(x))
	{
		cn++;
		v[x]=1;
		dfs(x+1);
		cn--;
	}
	if(cn+n-x>bestn)
	{
		v[x]=0;
		dfs(x+1);
	}
	return;
}


int main()
{
	int i,j;
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		    scanf("%d",&a[i][j]);
		memset(v,0,sizeof(v));
		cn=bestn=0;
		dfs(1);    
		printf("%d\n",bestn);
	}
} 
