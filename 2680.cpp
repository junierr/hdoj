#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int>ddd;
int n,s;
int map[1004][1004];
void dd(int x)
{
	int i,j,next=x,min;
	int v[1004],d[1004];
	for(i=1;i<=n;i++)
	{
		d[i]=map[x][i];
		v[i]=0;
	}
	v[x]=1;
	for(i=1;i<=n;i++)
	{
		min=999999;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0&&min>d[j])
			{
				min=d[j];
				next=j;
			}
		}
		v[next]=1;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0&&d[j]>d[next]+map[next][j])
			  d[j]=d[next]+map[next][j];
		}
	}
	min=99999;
	for(i=1;i<=n;i++)
	{
		if(ddd.count(i)==1&&min>d[i]) min=d[i];
	}
	if(min==99999) printf("-1\n");
	else printf("%d\n",min); 
	return ;
}
int main()
{
	int i,j,m,w,p,q,t,x;
	while(~scanf("%d%d%d",&n,&m,&s))
	{
		ddd.clear();
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	if(i==j) map[i][j]=0;
		  	else map[i][j]=999999;
		  }
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&q,&p,&t);
			if(t<map[p][q])
			  map[p][q]=t;
		}
		scanf("%d",&w);
		for(i=0;i<w;i++)
		{
			scanf("%d",&x);
			ddd.insert(x);
		}
		dd(s);
	}
	return 0;
}
