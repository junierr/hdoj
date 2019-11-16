#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int b[1000];
	int n,t=0;
	while(~scanf("%d",&n))
	{
		getchar();
		for(int x=1;x<=n;x++)
		{
		gets(a);
		for(int i=0;i<strlen(a);i++)
		{
		    if((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')||(a[0]=='_')) t=1;
			else 
			{
			   printf("no\n");
			   break;
		    }
			if((a[i]>='_'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')) t=1;
			else
			{
				printf("no\n");t=0;
				break;
			}
		}
		if(t==1) printf("yes\n");
		t=0;
       }
	}
	return 0;
 } 
