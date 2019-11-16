#include<stdio.h>
int main()
{
	int t,a,b,sum;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&a,&b);
			sum=(a%100+b%100)%100;
			printf("%d\n",sum);
		}
	}
	return 0;
}
