#include<stdio.h>
int main()
{
	int m,n;
	int f[100];
	while(~scanf("%d",&m))
	{
		f[0]=0;f[1]=1;f[2]=1;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&n);
			for(int j=3;j<=n;j++)
			{
				f[j]=f[j-1]+f[j-2];
			}
			printf("%d\n",f[n]);
		}
	}
	return 0;
}
