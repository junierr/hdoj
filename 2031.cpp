#include<stdio.h>
int main()
{
	long n;
	int m,x,y;
	int a[1000];
	while(~scanf("%d %d",&n,&m))
	{
		if(n<0)
		{
			n=-n;
			printf("-");
		}
		int i=0;
		while(n!=0)
		{
			a[i]=n %m;
			i++;
			n=n/m;
		}
		while(i--)
		{
			if(i==0)
			{
			   if(a[i]==10) printf("A\n");
			   else if(a[i]==11) printf("B\n");
		       else if(a[i]==12) printf("C\n");
			   else if(a[i]==13) printf("D\n");
			   else if(a[i]==14) printf("E\n");
			   else if(a[i]==15) printf("F\n");	
			   else printf("%d\n",a[i]);
			}
			
			else
			{
			   if(a[i]==10) printf("A");
			   else if(a[i]==11) printf("B");
			   else if(a[i]==12) printf("C");
			   else if(a[i]==13) printf("D");
			   else if(a[i]==14) printf("E");
			   else if(a[i]==15) printf("F");
			   else printf("%d",a[i]);
		    }
		}
	}
	return 0;    
}
