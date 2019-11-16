#include<stdio.h>
int main()
{
	long long f[1000];
	int n;
	while(~scanf("%d",&n))
	{
		f[0]=0;f[1]=3;f[2]=6;f[3]=6;
		for(int i=4;i<=n;i++)
		{
			f[i]=f[i-1]+2*f[i-2];
		}
		printf("%lld\n",f[n]);
	}
	return 0;
 } 
