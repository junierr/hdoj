#include<bits/stdc++.h>
using namespace std;
int s[10000];
struct point 
{
	int x,y,len;
}a[10000];

int cmp(const point x,const point y)
{
	return x.len<y.len;
}

int find(int x)
{
	int r=x;
	while(s[r]!=r)
	{
		r=s[r];
	}
	s[x]=r;
	return r;
}
void hb(int x,int y)
{
	s[x]=s[y];
}

int main()
{
	int n,i,j,t,hx,hy,x,y,q,sum;
	while(~scanf("%d",&n))
	{
		t=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[t].len);
				a[t].x=i;
				a[t].y=j;
				t++;
			}
		}
		for(i=0;i<=n;i++) s[i]=i;
		sum=0;
		sort(a,a+t,cmp);
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&x,&y);
			hx=find(x-1);
			hy=find(y-1);
			if(hx!=hy) hb(hx,hy);
		}
		for(i=0;i<t;i++)
		{
			hx=find(a[i].x);
			hy=find(a[i].y);
			if(hx!=hy)
			{
				sum+=a[i].len;
				hb(hx,hy);
			}
		}
	    printf("%d\n",sum);
	}
	return 0;
 } 
