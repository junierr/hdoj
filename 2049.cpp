#include<stdio.h>

long long x(int y)
{
	long long o;
	o=1;
	for(int i=1;i<=y;i++)
	o=o*i;
	return o;
}


int main()
{
	int n,m,c;
	long long f[25];
	int p;
	while(~scanf("%d",&c))
	{
		while(c--)
		{
		  scanf("%d %d",&n,&m);
          f[0]=0;f[1]=0;f[2]=1;
		  for(int i=3;i<=m;i++)
		    f[i]=(i-1)*(f[i-1]+f[i-2]);
		  p=1;
		  p=x(n)/(x(m)*x(n-m));
		  printf("%lld\n",p*f[m]);
	    }
	}
	return 0;
 } 
