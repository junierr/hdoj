#include<stdio.h>
#include<math.h>
int main()
{
	int m=0,n=0;
	int sum=0,i=0,s=0;
	int a=0,b=0,c=0;
	int d[1000];
	while(~scanf("%d %d",&m,&n))
	{
		for(i=m;i<=n;i++)
		{
			a=i /100;
			b=i %10;
			c=i /10 %10;
			sum=a*a*a+b*b*b+c*c*c;
			if (sum==i)
			{
				s=s+1;
				d[s]=sum;
			}
		}
		if(s==0)
		{
			printf("no\n");	
		}
		else for(i=1;i<=s;i++)
		{
			if (i<s)
			{
				printf("%d ",d[i]);
			}	
			if(i==s)
			{
				printf("%d\n",d[i]);
			}
			
		}
		s=0;
	}
	return 0;
}
