#include<stdio.h>
int main()
{
	int n,a,b,sum=0;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
		scanf("%d %d",&a,&b);
	    sum=a+b;
	    printf("%d\n",sum);
	    }
    }
	return 0;
	
}
