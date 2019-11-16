#include<bits/stdc++.h>
using namespace std;
	struct point
	{
		double x,y,len;
	}a[10000];
double cmp(const point a,const point b)
{
	return a.len>b.len;
}


int main()
{
	int n,i;
	while(~scanf("%d",&n)&&(n!=-1))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			a[i].len=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
			a[i].len=-(a[i].y/a[i].len);
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			if(i==0) 
			{
				printf("%.1f %.1f",a[i].x,a[i].y);
			}
			else printf(" %.1f %.1f",a[i].x,a[i].y);
		}
		printf("\n");
	}
	return 0;
 } 
