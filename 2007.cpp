#include<stdio.h>
int main()
{
	int m,n,i,sum=0,dum=0,t=0;
	while(~scanf("%d %d",&m,&n))
	{
		if(m>n)
		{
			t=m;m=n;n=t;
		}
		for(i=m;i<=n;i++)
		{
			if(i % 2 == 0)
			{
				sum=sum+i*i;
			}
			else 
			{
				dum=dum+i*i*i;
			}
		}
		printf("%d %d\n",sum,dum);
		sum=0;dum=0;
	}
	return 0;
}
