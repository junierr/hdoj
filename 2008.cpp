#include<stdio.h>
int main()
{
	int sum=0,dum=0,fum=0,i=0;
	double n=0;
	double a[1000];
	while(~scanf("%lf",&n))
	{
		if(n !=0)
		{
		
		for(i=1;i<=n;i++)
		{
			scanf(" %lf",&a[i]);
			if(a[i]==0)
			{
				dum=dum+1;
			}
			if (a[i]<0)
			{
				sum=sum+1;
			}
			if (a[i]>0)
			{
				fum=fum+1;
			}
		}
		printf("%d %d %d\n",sum,dum,fum);sum=0;dum=0;fum=0;
	}	
   } 
	return 0;
}
