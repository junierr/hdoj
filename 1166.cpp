#include<cstdio>
#include<cstring>
using namespace std;
int c[50005];
int n;

int lowbit(int x)
{
	return (x&(-x));
}

void update(int x,int y)
{
	for(;x<=n;c[x]+=y,x+=lowbit(x));
}

int sum(int x)
{
	int ret=0;
	for(;x>0;ret+=c[x],x-=lowbit(x));
	return ret;
}

int main()
{
	int T,t,i,j;
	char s[100];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(c,0,sizeof(c));
		printf("Case %d:\n",t);
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&i);
			update(j,i);
		}
		while(~scanf("%s",s))
		{
			if(s[0]=='E') break;
			scanf("%d%d",&i,&j);
			if(s[0]=='Q') printf("%d\n",sum(j)-sum(i-1));
			else if(s[0]=='A') update(i,j);
			else if(s[0]=='S') update(i,-j);
		}
	}
	return 0;
}
