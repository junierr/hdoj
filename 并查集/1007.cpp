#include<bits/stdc++.h>
using namespace std;
struct point
{
	int a,b,c;
}p[10000];
int a[10000];
int cmp(const point x,const point y)
{
	return x.c<y.c;
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
	int n,sum,i,hx,hy;
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++) a[i]=i;
		for(i=1;i<=n*(n-1)/2;i++) scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		sort(p+1,p+n*(n-1)/2+1,cmp);
		sum=0;
		for(i=1;i<=n*(n-1)/2;i++)
		{
			hx=find(p[i].a);
			hy=find(p[i].b);
			if(hx!=hy)
			{
			   hb(hx,hy);
			   sum+=p[i].c;
		    }
	    }
	    printf("%d\n",sum);
    } 
    return 0;
}
