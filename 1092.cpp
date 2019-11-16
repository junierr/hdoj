#include<stdio.h>
int main()
{
	int n,i=0,sum=0;
	int a[1000];
	while(~scanf("%d",&n))
	{
		if(n!=0)
		{
		for(i=1;i<=n;i++)
		{
			scanf(" %d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",sum);sum=0;
	    }
	}
	return 0;
 } 
