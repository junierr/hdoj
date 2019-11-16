#include<stdio.h>
int main()
{
	int a,b,s;
	while(~scanf("%d %d",&a,&b))
	if(!(a==0&&b==0))
	{
		s=a;
		for(int i=1;i<b;i++)
		{
			a=a%1000;
			a=a*s;
		}
		a=a%1000;
	    if(a/100!=0)
		{
		   printf("%d\n",a);
	    }
	    else if(a/10%10!=0)
	    {
	    	printf("%d\n",a%100);
		}
		else printf("%d\n",a%10);
	}
	return 0;
 } 
