#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y,z,t;
}s[10000];
int a[100000];

int cmp(const point x,const point y)
{
	return x.z<y.z;
}
int find(int x)
{
	int r=x;
	while(a[r]!=r)
	{
		r=a[r];
	}
	a[x]=r;
	return r;
}
void hb(int x,int y)
{
	a[x]=y;
}
int main()
{
	int n,i,sum,hx,hy;
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n*(n-1)/2;i++)
		{
			scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].z,&s[i].t);
			if(s[i].t==1) s[i].z=0; 
		}
		sort(s,s+n*(n-1)/2,cmp);
		sum=0;
		for(i=0;i<n*(n-1)/2;i++) a[i]=i;
		for(i=0;i<n*(n-1)/2;i++)
		{
			hx=find(s[i].x);
			hy=find(s[i].y);
			if(hx!=hy) 
			{
			  hb(hx,hy);
			  sum+=s[i].z;
		    } 
		}
		printf("%d\n",sum);
	}
	return 0;
}
