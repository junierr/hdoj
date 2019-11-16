#include<bits/stdc++.h>
using namespace std;
int a[100000];
struct point 
{
	int x,y;
	double z; 
}s[10000];
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

int cmp(const point x,const point y)
{
	return x.z<y.z;
}
void hb(int x,int y)
{
	a[x]=y;
}


int main()
{
	int t,c,i,j,k,hx,hy;
	double d;
	int x[100000],y[100000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&c);
		for(i=0;i<c;i++) scanf("%d%d",&x[i],&y[i]);
		k=0;
		for(i=0;i<c-1;i++)
		{
			for(j=i+1;j<c;j++)
			{
				d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(d>=10&&d<=1000)
				{
					s[k].x=i;
					s[k].y=j;
					s[k].z=d;
					k++;
				}
			}
		}
		int f=0;
		double sum=0;
		sort(s,s+k,cmp);
		for(i=0;i<=c;i++) a[i]=i;
		for(i=0;i<k;i++)
		{
			hx=find(s[i].x);
			hy=find(s[i].y);
			if(hx!=hy) 
			{
			   hb(hx,hy);
			   sum+=s[i].z;
			   f++;
		    }
		}
		if(f==c-1) printf("%.1lf\n",sum*100);
		else printf("oh!\n");
	}
	return 0;
 } 
