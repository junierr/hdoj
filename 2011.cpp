#include<stdio.h>
int main()
{
	double sum=0;
	int m=0,n=0,i=0,j=0;
	int a[1000];
	while(~scanf("%d\n",&m))
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
	        for(j=1;j<=a[i];j++)
			{
				if(j%2==1)
				{
					sum=sum+1/(j*1.0);
				}
				if(j%2==0)
				{
					sum=sum-1/(j*1.0);
				}
			}
			printf("%.2lf\n",sum);sum=0;	
		}
	}
	return 0;
 } 
