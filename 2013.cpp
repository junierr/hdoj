#include<stdio.h>
int main()
{
	int n,i=0;
	int sum=1;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n-1;i++)
		{
			sum=(sum+1)*2;
		}
		printf("%d\n",sum);
		sum=1;
	}
	return 0;
}
