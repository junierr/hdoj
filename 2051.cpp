#include<stdio.h>
void printx(int i,int j)
{
	int out;
	out=i%j;
	i/=j;
	if(i!=0)
	{
	   printx(i,2);
	   printf("%d",out);	
	}
	else printf("%d",out);
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
			printx(n,2);
			printf("\n");
	}
	return 0;
 } 
