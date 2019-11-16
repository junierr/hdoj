#include<stdio.h>
int main()
{
	int n;
	long long f[1000][3];
	while(~scanf("%d",&n))
	{
		f[0][0]=0;f[0][1]=0;f[0][2]=0;f[0][3]=0;
		f[1][1]=1;f[1][2]=1;f[1][3]=1;
		f[2][1]=3;f[2][2]=2;f[2][3]=3;
		for(int i=3;i<=n;i++)
		  {
		  	f[i][1]=f[i-1][1]+f[i-1][2]+f[i-1][3];
		  	f[i][2]=f[i-1][1]+f[i-1][3];
		  	f[i][3]=f[i-1][1]+f[i-1][2]+f[i-1][3];
		  }
		  printf("%lld\n",f[n][1]+f[n][2]+f[n][3]);
	}
	return 0;
}
