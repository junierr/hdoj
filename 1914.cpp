#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
map<char,int> b,g;
map<int,char> bb,gg;
queue<int>d;

int ranka[30][30],rankb[30][30];
int wife[30],husband[30],h[30];

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
	int T,i,j,n;
	int a[1000];
	char s1,s2;
	char c1,c2;
	cin>>T;
	getchar();
	while(T--)
	{
		b.clear();
		g.clear();
		bb.clear();
		gg.clear();
		memset(ranka,0,sizeof(ranka));
		memset(rankb,0,sizeof(rankb));
		memset(h,0,sizeof(h));
		d=queue<int>();
		cin>>n;
	    for(i=1;i<=n;i++) 
	    {
	    	cin>>s1;
	    	a[i]=s1;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			b[a[i]]=i;
			bb[i]=a[i];
		}
		for(i=1;i<=n;i++)
		{
			cin>>s2;
			g[s2]=i;
			gg[i]=s2;
		}
		for(i=1;i<=n;i++)
		{
			cin>>c1;
			cin>>c2;
			for(j=1;j<=n;j++)
			{
				cin>>c2;
				ranka[b[c1]][j]=g[c2];
			}
			h[b[c1]]=1;
			d.push(i);
		}
		for(i=1;i<=n;i++)
		{
			cin>>c1;
			cin>>c2;
			for(j=1;j<=n;j++)
			{
				cin>>c2;
				rankb[g[c1]][b[c2]]=j;
			}
		}
		pp();
		for(i=1;i<=n;i++)
		{
			printf("%c %c\n",bb[i],gg[husband[i]]);
		}
		if(T!=0) printf("\n");
	}
	return 0;
}
