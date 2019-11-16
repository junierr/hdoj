#include<cstdio>
#include<cstring>
using namespace std;
struct mar
{
	double m[205][205];
}ans,res,ar;
int n;

mar mul(mar a,mar b)
{
	mar tmp;
	int i,j,k;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    tmp.m[i][j]=0;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    for(k=0;k<n;k++)
		  tmp.m[i][j]+=a.m[i][k]*b.m[k][j];
	return tmp;	      
}

void quick(int m)
{
	int i,j;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    if(i==j) ans.m[i][j]=1;
	    else ans.m[i][j]=0;
	while(m)
	{
		if(m&1) 
		  ans=mul(res,ans);
		res=mul(res,res);
		m=m>>1;  
	}
	ar=mul(ans,ar);
	printf("%.0f\n",ar.m[n-1][0]);
}


int main()
{
	int m,t,x,y,i,j;
	double p;
	while(~scanf("%d%d",&n,&m),n||m)
	{
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		    if(i==j) res.m[i][j]=1;
		    else res.m[i][j]=0;
		for(i=0;i<n;i++)
		  scanf("%lf",&ar.m[i][0]);
		scanf("%d",&t);
		for(i=0;i<t;i++)
		{
			scanf("%d%d%lf",&x,&y,&p);
			res.m[y][x]+=p;
			res.m[x][x]-=p;
		}
		quick(m);   
	}
	return 0;
}
