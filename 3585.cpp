#include<cstdio>
#include<cstring>
using namespace std;

struct pp
{
	double x,y;
}a[55];

int ans,v[55][55],k,f[55];
double d[55][55];

double jl(pp x,pp y)
{
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}

bool dfs(int aa[],int num,int step)
{
	int i,j;
	if(num==0)
	{
		if(step>ans)
		{
			ans=step;
			return 1;
		}
		return 0;
	}
	for(i=1;i<=num;i++)
	{
		if(step+num-i+1<=ans)
		  continue;
		if(step+f[aa[i]]<=ans)
		  continue;
		int t[55],num2=0;
		for(j=i+1;j<=num;j++)
		  if(v[aa[i]][aa[j]])
		    t[++num2]=aa[j];
		if(dfs(t,num2,step+1))
		  return 1;	    
	}
	return 0;
}


void mmax(int n)
{
	int aa[55],num,i,j;
	for(i=n-1;i>=0;i--)
	{
		num=0;
		for(j=i+1;j<n;j++)
		  if(v[i][j])
		    aa[++num]=j;
		dfs(aa,num,1);
		if(ans>=k) return;
		f[i]=ans;    
	}
}

int main()
{
	int n;
	int i,j;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
		memset(d,0,sizeof(d));
		for(i=0;i<n;i++)
		  for(j=i+1;j<n;j++)
		    d[i][j]=d[j][i]=jl(a[i],a[j]);
		double l=0,r=20000;
		while(r-l>1e-4)
		{
			ans=0;
			double mid=(l+r)/2;
			memset(v,0,sizeof(v));
			for(i=0;i<n;i++)
			  for(j=i+1;j<n;j++)
			    if(d[i][j]>=mid*mid) v[i][j]=v[j][i]=1;
			    else v[i][j]=v[j][i]=0;
			mmax(n);
			if(ans>=k) l=mid;
			else r=mid;    
		}
		printf("%.2f\n",l);    
	}
	return 0;
}
