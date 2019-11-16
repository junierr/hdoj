#include<stdio.h>
int main()
{
	int n,t=0,i,j;
	char c;
	while(~scanf("%s",&c)&&(c!='@'))
	{
		if(t!=0) printf("\n");
		scanf("%d",&n);
		for( i=1;i<=n;i++)
		{
			if(i==1)
			{
				for(j=1;j<=n-i;j++) printf(" ");
		    	printf("%c\n",c);
			 } 
			else if(i==n) 
			{
			   for( j=1;j<=2*n-1;j++) printf("%c",c);
			   printf("\n");
		    }
		    else 
		    {
		    	for( j=1;j<=n-i;j++) printf(" ");
		    	printf("%c",c);
		    	for( j=1;j<=2*i-3;j++) printf(" ");
		    	printf("%c\n",c);
			}
		}
		t++;
	}
	return 0;
 } 
