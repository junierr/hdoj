#include<stdio.h>
int main()
{
	int n,m;
	long long sum;
	while(~scanf("%d",&m))
	{
		
		for(int i=1;i<=m;i++)
		{
		  scanf("%d",&n);
		  sum=2*n*n-n+1;
		  printf("%lld\n",sum);
	    }
	}
	return 0;
 } 
