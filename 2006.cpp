#include<stdio.h>
int main()
{
	int n,i=0;int sum=1;
	int a[1000];
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf(" %d",&a[i]);
			if(a[i]%2==1)
			{
				sum=sum*a[i];
			}
		}
		printf("%d\n",sum);
		sum=1;
    }
    return 0;
} 
