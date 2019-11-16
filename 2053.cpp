#include<stdio.h>
int main()
{
	long long n;
	int a[200000];
	while(~scanf("%lld",&n))
	{
		for(int i=1;i<=n;i++) a[i]=0;
		for(int j=1;j<=n;j++)
		{
		   	  if(n%j==0&&a[n]==0) a[n]=1;
			  else if(n%j==0&&a[n]==1) a[n]=0;	  
		}
		printf("%d\n",a[n]);
	}
	return 0;
 } 
