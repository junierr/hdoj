#include<stdio.h>
#include<string.h>
int main()
{
	int n,sum;
	char s[1000];
	while(~scanf("%d",&n))
	{
		getchar();
		while(n--)
		{
			sum=0;
			gets(s);
            for(int i=0;i<strlen(s);i++)
			{
				if(s[i]<0) sum++;
			}
			printf("%d\n",sum/2);		
		}
		
	}
	return 0;
 } 
