#include<stdio.h>
int main()
{
	int n,max,t,sum,z;
	int a[1000];
	int b[1000];
	while(~scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		for(int j=0;j<n;j++)
		   for(int k=j+1;k<n;k++)
		   {
		   	  if(b[j]>b[k])
		   	  {
		   	  	t=a[j];
			    a[j]=a[k];
				a[k]=t;
		   	  	t=b[j];
				b[j]=b[k];
				b[k]=t;
			  }
		   }
		 	sum=1;z=0;
		 	for(int y=1;y<n;y++)
		 	{
		 		if(a[y]>=b[z])
		 		{
		 			sum++;
		 			z=y;
				 }
			 }
		  printf("%d\n",sum);   
	}
	return 0;
 } 
