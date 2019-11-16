#include<stdio.h>
int main()
{
	int n,a,b,c,sum,count;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			count=7;sum=b;
			if(a<=6)
			{
				for(int i=1;i<=a;i++)
				{
					sum+=count;
					count--;
				}
			}
			else if(a>6)
			{
				sum+=(a-6)*8+27;
			}
	        if(sum>=c) printf("Yes\n");
		else printf("No\n");
		}
		
	}
	return 0;
}
