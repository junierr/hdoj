#include<stdio.h>
int main()
{
	int n;
	int a[100][100];
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		  {
		  for(int j=1;j<=i;j++)
		  {
		  	if(j==1) a[i][j]=1;
		  	if(j==i) a[i][j]=1;
			  else a[i][j]=a[i-1][j-1]+a[i-1][j];
            if(j==i) printf("%d\n",a[i][j]);
			else printf("%d ",a[i][j]);		  
		  }
		  if(i==n) printf("\n");
	      }
	}
	return 0;
}
