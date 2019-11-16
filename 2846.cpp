#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int trie[500005][26];
int val[500005];
int flag[500005];
int tot,root;

void insert(char s[],int n)
{
	root=0;
	int i;
	for(i=0;s[i];i++)
	{
		int x=s[i]-'a';
		if(trie[root][x]==0) 
		{
		  trie[root][x]=++tot;
		  flag[trie[root][x]]=n;
		  val[trie[root][x]]++;
	    }
		root=trie[root][x];
	if(flag[root]!=n)
	{
		val[root]++;
		flag[root]=n;
	}
	}
}
int find(char s[])
{
	root=0;
	int i;
	for(i=0;s[i];i++)
	{
		int x=s[i]-'a';
		if(trie[root][x]==0) return 0;
		root=trie[root][x];
	}
	return val[root];
}

int main()
{
	int n,m,i,j;
	char s[10000];
	memset(trie,0,sizeof(trie));
	memset(val,0,sizeof(val));
	memset(flag,-1,sizeof(flag));
	scanf("%d",&n);
		tot=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;s[j];j++)
			  insert(s+j,i);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			printf("%d\n",find(s));
		}
	return 0;
}
