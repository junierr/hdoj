#include<stdio.h>
int main()
{
	int n=0,i=0,min=9999,s=0,t=0;
	int a[100];
	while(~scanf("%d",&n))
	{
		if(n!=0)
		{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
			{
				min=a[i];s=i;
		    }			
		}
		min=9999;
		t=a[1];a[1]=a[s];a[s]=t;
		for(i=1;i<=n;i++)
		{
			if(i!=n)
			{
				printf("%d ",a[i]);
			}
			if(i==n)
			{
				printf("%d\n",a[i]);
			}
		}
		
	     }
    }
	return 0;
}
