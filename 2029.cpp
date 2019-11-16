#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,judge=0;
	char a[105];
	while(~scanf("%d",&n))
	{
		getchar();
		while(n--)
		{
			gets(a);
			i=0;j=strlen(a)-1;
			while(i+1!=j&&i!=j)
			{
				if(a[i]!=a[j]) judge=1;
				i++;
				j--;
			}
			if(judge==1) printf("no\n");
			if(judge==0) printf("yes\n");
			judge=0;
		}
	}
	return 0;
 } 
