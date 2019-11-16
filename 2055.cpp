#include<stdio.h>
int main()
{
	int n,b,sum;
	char a;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			getchar();
			scanf("%c %d",&a,&b);
			sum=0;
			if(a>='A'&&a<='Z')
			{
				sum=a-64+b;
			}
			else sum=0-a+96+b;
		    printf("%d\n",sum);
		}
	}
	return 0;
 } 
