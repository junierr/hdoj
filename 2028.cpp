#include<stdio.h>
int main()
{
	 long int n,min,s,judge,sum=0;
	int a[105];
	while(~scanf("%ld",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i==1) {min=a[1];s=1;}
			 else if(a[i]<min) {min=a[i];s=i;}
		}
		judge=0;
		while(judge!=1)
		{
			for(int j=1;j<=n;j++)
			{
				if(min%a[j]==0) sum=sum+1; 
			}
			if(sum!=n) 
			{
			   judge=0;
			   min=min+a[s];
			   sum=0;
		    }
		    if(sum==n)
		    {
		    	judge=1;
		    	sum=0;
			}
		}
		printf("%ld\n",min);
	}
	return 0;
 } 
