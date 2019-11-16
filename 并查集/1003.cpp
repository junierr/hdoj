#include<bits/stdc++.h>
using namespace std;
int a[10000001],c[10000001];
int  manx;
int find(int x)
{
	int r=x;
	while(c[r]!=r)
	{
		r=c[r];
	}
	c[x]=r;
	return r;
 } 

void hb(int x,int y)
{
	if(x!=y) 
	{
	  c[x]=y;
	  a[y]+=a[x];
    }
    if(a[y]>manx) manx=a[y];
}

int main()
{
	int n,i,x,y,hx,hy;
	while(~scanf("%d",&n))
	{
		manx=0;
		if(n==0) 
		{
		  printf("1\n");
		  continue;
	    }
		for(i=1;i<=10000000;i++) 
		{
		  c[i]=i;
		  a[i]=1;
	    }
		for(i=1;i<=n;i++) 
		{
		    scanf("%d%d",&hx,&hy);
			x=find(hx);
			y=find(hy);
			hb(x,y);
		}
		printf("%d\n",manx);
	}
	return 0;
}
