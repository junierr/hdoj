#include<stdio.h>
int main()
{
	int n,a,sum;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum=3;
			for(int j=0;j<a;j++)
			{
				sum=(sum-1)*2;
			}
			printf("%d\n",sum);		}
	}
	return 0;
 } 
