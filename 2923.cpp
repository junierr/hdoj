#include<bits/stdc++.h>
using namespace std;
map<string,int> mm;
char mapp[1005][1005];
char s1[1005],s2[1005];
int f[1005][1005];

void floyd(int n,int c,int r)
{
	int i,j,k,t,m,l,ans,cnt;
	char c1,c2;
	cnt=0;
	mm.clear();
	memset(f,99999,sizeof(f));
	for(i=0;i<=c;i++)
	{
		scanf("%s",mapp[i]);
		if(!mm[mapp[i]]) mm[mapp[i]]=++cnt;
	}
	for(i=1;i<=r;i++)
	{
		scanf("%s %c-%d-%c %s",s1,&c1,&l,&c2,s2);
		if(!mm[s1]) mm[s1]=++cnt;
		if(!mm[s2]) mm[s2]=++cnt;
		k=mm[s1];t=mm[s2];
		if(c1=='<') f[t][k]=min(f[t][k],l);
		if(c2=='>') f[k][t]=min(f[k][t],l);
	}
	for(k=1;k<=n;k++)
	  for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	      f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	ans=0;
	k=mm[mapp[0]];
	for(i=1;i<=c;i++)
	  ans+=f[k][mm[mapp[i]]+f[mm[mapp[i]]][k]];
	printf("%d\n",ans);
	return;        
}

int main()
{
	int T,n,c,r;
	T=1;
	while(~scanf("%d%d%d",&n,&c,&r),n||c||r)
	{
		printf("%d. ",T++);
		floyd(n,c,r);
	}
}
