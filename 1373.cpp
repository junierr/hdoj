#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int flag,n;
int color[30],map[30][30];
int check(int a,int b)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(map[i][a]&&color[i]==b)  //相邻并且使用同一个中继站 
		return 0;
	}
	return 1;
}

void dfs(int a,int b)
{
	int i;
	if(flag==1) return;
	if(a==n) //找完了 
	{
		if(b-1>1) printf("%d channels needed.\n",b-1);
		else printf("%d channel needed.\n",b-1);
		flag=1;
		return;
	}
	for(i=1;i<b;i++)
	{
		if(check(a,i)) //i是假设的中继站 
		{
			color[a]=i;
			dfs(a+1,b);
		}
	}
	color[a]=b;
	dfs(a+1,b+1); 
}




int main()
{
	int i,j;
	char s[100];
	while(~scanf("%d",&n)&&n)
	{
		flag=0;
		memset(map,0,sizeof(map));
		memset(color,-1,sizeof(color));
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			int len=strlen(s);
			int a=s[0]-'A';
			for(j=2;j<len;j++)
			{
				int b=s[j]-'A';
				map[a][b]=map[b][a]=1;
			}	
		}
		dfs(0,1);
	}
	return 0;
}
 
