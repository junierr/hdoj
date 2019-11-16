#include<stdio.h>
#include<math.h>
int main()
{
	int n=0,m=0,i=0;
	double a[1000];
	double sum=0;
	while(~scanf("%d %d",&n,&m))
	{
		for(i=2;i<=m;i++)
		{
			a[1]=n;
			a[i]=sqrt(a[i-1]);
		}
		for(i=1;i<=m;i++)
		{
			sum=sum+a[i];
		}
		printf("%.2lf\n",sum);sum=0;
	}
	return 0;
}
