#include<stdio.h>
int main()
{
	int n,a;
	long long f[100];
	long long b;
		scanf("%d",&n);
		while(n--)
		{
		scanf("%d",&a);
		f[0]=0;f[1]=0;f[2]=1;b=1;
		for(int i=3;i<=a;i++)
		{
			f[i]=(i-1)*(f[i-1]+f[i-2]);
		}
		for(int j=1;j<=a;j++)
		{
			b=b*j;
		}
		
		
		  
		  printf("%.2lf%%\n",(double) f[a]/b*100);
	    }
	return 0;
 } 
