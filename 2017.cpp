#include<stdio.h>
#include<string.h>
int main()
{
	char a[500];
	int n=0,i=0,sum=0,d=0,j=0;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",a);
			d=strlen(a);
			for(j=0;j<d;j++)
			{
				if((a[j]>='0')&&(a[j]<='9'))
				{
					sum=sum+1;
				}
		    }
			printf("%d\n",sum);sum=0;
		}
	}
	return 0;
}
