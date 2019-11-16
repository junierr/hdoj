#include<bits/stdc++.h>
using namespace std;
char a[10][10];
int n,m,t,di,dj;
bool escape;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
bool dfs(int si,int sj,int cnt)
{
	int i;
	if(si>n||sj>m||si<=0||sj<=0) return escape;
	if(cnt==t&&si==di&&sj==dj) escape=1;
	if(escape) return escape;
	for(i=0;i<4;i++)
	{
		if(a[si+dir[i][0]][sj+dir[i][1]]!='X')
		{
			a[si+dir[i][0]][sj+dir[i][1]]='X';
			dfs(si+dir[i][0],sj+dir[i][1],cnt+1);
			a[si+dir[i][0]][sj+dir[i][1]]='.';
		}
	}
	return escape;
}

int main()
{
	int i,j,si,sj,wall,temp;
	while(cin>>n>>m>>t)
	{
		if(n==0&&m==0&&t==0) break;
		wall=0;
		for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++)
			{
			   cin>>a[i][j];
               if(a[i][j]=='S')
			   {
			   	si=i;sj=j;
				}
				else if(a[i][j]=='D')
				{
					di=i;dj=j;
				}
				else if(a[i][j]=='X')
				{
					wall++;
				}
			}
				if(n*m-wall<=t)
				{
					printf("NO\n");
					continue;
				}
				escape=0;
				a[si][sj]='X';
				temp=t-abs(si-di)-abs(sj-dj);
				if(temp<0||temp%2==1) 
				{
					printf("NO\n");
					continue;
				}
				dfs(si,sj,0);
				if(escape) printf("YES\n");
				else printf("NO\n");					    
	}
	return 0;
 } 
