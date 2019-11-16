#include<stdio.h>
int main()
{
	double dum=0;
	int i=0,n=0,sum=0,max=0,min=101;
	int a[1000];
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]>max)
			{
				max=a[i];
			}
			if (a[i]<min)
			{
				min=a[i];
			}
			sum=sum+a[i];
		}
		sum=sum-max-min;
		dum=sum/((n-2)*1.0);
		printf("%.2lf\n",dum);
		sum=0;max=0;min=101;
	}
	return 0;
}
