#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int a=0,e=0,i=0,o=0,u=0;
	char s[105];
	scanf("%d",&n);
	getchar();
		while(n--)
		{
			gets(s);
			for(int j=0;j<strlen(s);j++)
			{
				switch(s[j])
				{
					case 'a':a=a+1;break;
					case 'e':e=e+1;break;
					case 'i':i=i+1;break;
					case 'o':o=o+1;break;
					case 'u':u=u+1;break;
				}
			}
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
			a=0;e=0;i=0;o=0;u=0;
			if(n) printf("\n");
		}
	return 0;
}
