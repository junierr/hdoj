#include<stdio.h>
int main()
{
	int n,m;
	int sum=0,i=0,j=0;
	int a[1000];
	while(~scanf("%d",&n))
	{
		for(j=1;j<=n;j++)
		{
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf(" %d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",sum);sum=0;
		if(j!=n)
		{
			printf("\n");
		}
	    } 
	}
	return 0;
}
