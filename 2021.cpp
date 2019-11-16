#include<stdio.h>
int main()
{
	int n,x=0,a=0;
	int q,w,e,r,t;
	while(~scanf("%d",&n))
	{
		if(n!=0)
		{
			for(int i=1;i<=n;i++)
			{
			   scanf("%d",&a);
			   q=a/100;
			   a=a-q*100;
			   t=a/50;
			   a=a-t*50;
			   w=a/10;
			   a=a-w*10;
			   e=a/5;
			   a=a-e*5;
			   r=a/2;
			   a=a-r*2;
			   x=x+q+w+e+r+a+t;			   
		    }
		    printf("%d\n",x);
		    x=0;
			
		}
	}
	return 0;
 } 
