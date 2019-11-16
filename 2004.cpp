#include<stdio.h>
int main()
{
	int n=0;
	while(~scanf("%d",&n))
	{
		if ((0<=n)&&(n<=59))
		{
			printf("E\n");
		}
		if ((60<=n)&&(n<=69))
		{
			printf("D\n");
		}
		if ((70<=n)&&(n<=79))
		{
			printf("C\n");
		}
		if ((80<=n)&&(n<=89))
		{
			printf("B\n");
		}
		if ((90<=n)&&(n<=100))
		{
			printf("A\n");
		}
		if ((n<0) || (n>100))
		{
			printf("Score is error!\n");
		}
		}
		return 0;
	}
