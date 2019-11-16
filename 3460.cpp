#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int trie[400005][26];
int tot;
void insert(char s[])
{
	int i,rt;
	rt=0;
	for(i=0;s[i];i++)
	{
		int x=s[i]-'a';
		if(trie[rt][x]==0) trie[rt][x]=++tot;
		rt=trie[rt][x];
	}
}


int main()
{
	char s[55];
	int max,i,len,n;
	while(~scanf("%d",&n))
	{
		max=0;
		tot=0;
		memset(trie,0,sizeof(trie));
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			if(max<len)max=len;
			insert(s);
		}
		printf("%d\n",n+tot*2-max);
	}
}
