#include<stdio.h>
int main()
{
	int n,t=0;
	int a[1000],b[1000];
	while(~scanf("%d",&n))
	{
		if(n!=0)
		{
		for(int i=1;i<=n;i++)
		{
			scanf(" %d",&a[i]);
			b[i]=0;
			if(a[i]<0)
			{
				a[i]=0-a[i];
				b[i]=1;
			}
		}
		for(int j=1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[j]<a[k])
				{
					t=a[j];a[j]=a[k];a[k]=t;
					t=b[j];b[j]=b[k];b[k]=t;
				}
			}
		}
		for(int l=1;l<n;l++)
		{
			if(b[l]==0)
			{
				printf("%d ",a[l]);
			}
			if(b[l]==1)
			{
				printf("%d ",-a[l]);
			}			
		}
		if(b[n]==0)
		{
			printf("%d\n",a[n]);
		}
		if(b[n]==1)
		{
			printf("%d\n",-a[n]);
		}
	    }
    }
	return 0;
}
