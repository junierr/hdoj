#include<stdio.h>
int main()
{
	int n,s1,s2,m1,m2,h1,h2,hour,second,min;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			hour=0;second=0;min=0;
			scanf("%d %d %d %d %d %d",&h1,&m1,&s1,&h2,&m2,&s2);
			hour=h1+h2;
			min=m1+m2;
			if(min>=60) 
			{
				min=min%60;
				hour++;
			}
			second=s1+s2;
			if(second>=60)
			{
				second=second%60;
				min++;
			}
			printf("%d %d %d\n",hour,min,second);
		}
	}
	return 0;
 } 
