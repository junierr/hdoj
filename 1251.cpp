#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int trie[400005][26],len,root,tot=0,sum[400005];

void insert(char s[])
{
	int i;
	len=strlen(s);
	root=0;
	for(i=0;i<len;i++)
	{
		int x=s[i]-'a';
		if(trie[root][x]==0) 
		  trie[root][x]=++tot;
		sum[trie[root][x]]++;
		root=trie[root][x];  
	}
}
int find(char s[])
{
	int i;
	root=0;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		int x=s[i]-'a';
		if(trie[root][x]==0) return 0;
		root=trie[root][x];
	}
	return sum[root];
}


int main()
{
	char s[20];
	int i,ans;
	memset(trie,0,sizeof(trie));
	memset(sum,0,sizeof(sum));
	while(gets(s)&&s[0]!='\0')
	  insert(s);
	memset(s,0,sizeof(s));
	while(~scanf("%s",&s)) 
	{
		ans=find(s);
		printf("%d\n",ans);
	 }
	return 0;  
 } 
