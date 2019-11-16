#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 10010
using namespace std;
char s[N][11];
int trie[N][11];
int word[N];
int tot;
void insert(char s[])
{
	int i,j,l=strlen(s);
	int root=0;
	for(i=0;i<l;i++)
	{
		j=s[i]-'0';
		if(!trie[root][j])
		{
			trie[root][j]=tot++;
		}
		root=trie[root][j];
		word[root]++;
	}
}
int find(char *s)
{
	int i,j,l=strlen(s);
	int root=0;
	for(i=0;i<l;i++)
	{
		j=s[i]-'0';
		root=trie[root][j];
		if(word[root]==1)
			return 1;
	}
	return 0;
}
int main()
{
	int n,i,k;
	int T=1;
	while(~scanf("%s",s[0]))
	{
		k=1;
		while(~scanf("%s",s[k]))
		{
			if(s[k][0]=='9') break;
			k++;
		}
		memset(trie,0,sizeof(trie));
		memset(word,0,sizeof(word));
		tot=1;
		for(i=0;i<k;i++)
			insert(s[i]);
		int flag=1;
		for(i=0;i<k;i++)
		{
			if(!find(s[i]))
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("Set %d is immediately decodable\n",T++);
		else
			printf("Set %d is not immediately decodable\n",T++);
	}
	return 0;
}

