#include<stdio.h>
int main()
{
	int m,n,s=9999;
	int a[1000];
	while(~scanf("%d %d",&n,&m))
	{
		if(n!=0)
		{ 
		  for(int i=1;i<=n;i++)
		  {
			scanf("%d",&a[i]);
			if(a[i]>m&&a[i]<s)
			{
				s=i;
			}
		  }
		  for(int j=n;j>=s;j--)
		  {
		  	a[j+1]=a[j];
		  }
		  a[s]=m;s=9999;
		  for(int k=1;k<=n+1;k++)
		  {
		  	if(k!=n+1)
			  {
			  	printf("%d ",a[k]);
		      }
		     if(k==n+1) 
		     {
		     	printf("%d\n",a[k]);
			 }
		  }
	    }
	}
	return 0;
}
