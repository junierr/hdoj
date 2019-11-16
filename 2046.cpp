#include<stdio.h>
int main()
{
	int n;
	long long f[1000];
	while(~scanf("%d",&n))
	{
		f[0]=0;f[1]=1;f[2]=2;f[3]=3;
		for(int i=4;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
		printf("%lld\n",f[n]);
	}
	return 0;
 } 
