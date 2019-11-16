#include<stdio.h>
#include<math.h>
int main()
{
	double d=0;
	int x,y,i=0,s=0,p=0,t=0;
	int sum=0,j=0;
	while(~scanf("%d %d",&x,&y))
	{
		if(x>y)
		{
			t=x;x=y;y=t;
		}
		if((x!=0)||(y!=0))
		{
		for(i=x;i<=y;i++)
		{
			s=i*i+i+41;
			d=sqrt(s);
			p=d/1;
			for (j=2;j<=p;j++)
			{
				if(s %j==0)
				{
					sum=sum+1;
				}
			}
			
		}
		if(sum!=0)
		{
			printf("Sorry\n");
		}
		if(sum==0)
		{
			printf("OK\n");
		}
		sum=0;
	}
    } 
    return 0;
}
