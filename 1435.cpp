#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
queue<int>dd;

int c,ranka[205][205],rankb[205][205];
int h[205],wife[205],husband[205];

struct p1
{
	int id,v;
	double x,y,z;
}a[205],b[205];

struct p2
{
	int id,v;
	double dist;
}rankk[205];

double jl(p1 x,p1 y)
{
	return(x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y)+(x.z-y.z)*(x.z-y.z);
}

bool cmp(p2 x,p2 y)
{
	if(x.dist==y.dist)
	  return x.v>y.v;
	else return x.dist<y.dist;   
} 

void init()
{
	int i,j;
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			rankk[j].dist=jl(a[i],b[j]);
			rankk[j].id=b[j].id;
			rankk[j].v=b[j].v;
		}
		sort(rankk,rankk+c,cmp);
		for(j=0;j<c;j++)
		  ranka[a[i].id][j]=rankk[j].id;
		h[a[i].id]=0;  
	}
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			rankk[j].dist=jl(b[i],a[j]);
			rankk[j].id=a[j].id;
			rankk[j].v=a[j].v;
		}
		sort(rankk,rankk+c,cmp);
		for(j=0;j<c;j++)
		{
			rankb[b[i].id][rankk[j].id]=j;
		}
	}
}
void pp()
{
	memset(wife,-1,sizeof(wife));
	memset(husband,-1,sizeof(husband));
	while(!dd.empty())
	{
		int man=dd.front();
		dd.pop();
		int girl=ranka[man][h[man]++];
		if(wife[girl]==-1)
		{
			wife[girl]=man;
			husband[man]=girl;
		}
		else if(rankb[girl][man]<rankb[girl][wife[girl]])
		{
			husband[wife[girl]]=-1;
			dd.push(wife[girl]);
			wife[girl]=man;
			husband[man]=girl;
		}
		else 
		{
			dd.push(man);
		}
	}
	return;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		dd=queue<int>();
		scanf("%d",&c);
		for(i=0;i<c;i++)
		{
			scanf("%d%d%lf%lf%lf",&a[i].id,&a[i].v,&a[i].x,&a[i].y,&a[i].z);
			dd.push(a[i].id);
		}
		for(i=0;i<c;i++)
		{
			scanf("%d%d%lf%lf%lf",&b[i].id,&b[i].v,&b[i].x,&b[i].y,&b[i].z);
		}
		init();
		pp();
		for(i=0;i<c;i++)
		   printf("%d %d\n",wife[b[i].id],b[i].id);
		if(n) printf("\n"); 
	}
	return 0;
}
