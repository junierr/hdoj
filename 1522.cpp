#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<queue>
using namespace std;
map<string,int>g,b;
queue<int>d;
int ranka[505][505],rankb[505][505];
int wife[505],husband[505],h[505];


void pp()
{
	memset(wife,-1,sizeof(wife));
	memset(husband,-1,sizeof(husband));
	while(!d.empty())
	{
		int man=d.front();
		int girl=ranka[man][h[man]++];
		d.pop();
		if(wife[girl]==-1)
		{
			wife[girl]=man;
			husband[man]=girl;
		}
		else if(rankb[girl][man]<rankb[girl][wife[girl]])
		{
			husband[wife[girl]]=-1;
			d.push(wife[girl]);
			wife[girl]=man;
			husband[man]=girl;
		}
		else d.push(man);
	}
	return;
}




int main()
{
	int n,i,j;
	char str1[505][100],str2[505][100],s[100],s1[100],s2[100];
	while(~scanf("%d",&n))
	{
		d=queue<int>();
		g.clear();
		b.clear();
		memset(ranka,0,sizeof(ranka));
		memset(rankb,0,sizeof(rankb));
		memset(h,0,sizeof(h)); 
		int tb=1,tg=1;
		for(i=1;i<=n;i++)
		{
			scanf("%s",str1[i]);
			b[str1[i]]=tb++;
			for(j=1;j<=n;j++)
			{
				scanf("%s",s);
				if(!g[s])
				{
					strcpy(str2[tg],s);
					g[s]=tg++;
				}
				ranka[b[str1[i]]][j]=g[s];
			}
			h[tb-1]=1;
			d.push(tb-1);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s",s1);
			for(j=1;j<=n;j++)
			{
				scanf("%s",s2);
				rankb[g[s1]][b[s2]]=j;
			}
		}
		pp();
		for(i=1;i<=n;i++)
		  printf("%s %s\n",str1[i],str2[husband[i]]);
		printf("\n");  
	}
	return 0;
 } 
