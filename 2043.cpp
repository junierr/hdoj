#include<stdio.h>
#include<string.h>
int main()
{
	int m,sum,a,b,c,d;
	char s[100];
	while(~scanf("%d",&m))
	{
		getchar();
		for(int i=1;i<=m;i++)
		{
			gets(s);
			sum=0;a=0;b=0;c=0;d=0;
			if(strlen(s)>=8&&strlen(s)<=16) sum=1;
			for(int j=0;j<strlen(s);j++)
			{
				if('a'<=s[j]&&s[j]<='z') a=1;
				if('A'<=s[j]&&s[j]<='Z') b=1;
				if('0'<=s[j]&&s[j]<='9') c=1;
				if(s[j]=='~'||s[j]=='!'||s[j]=='@'||s[j]=='#'||s[j]=='$'||s[j]=='%'||s[j]=='^') d=1;
			}
			if(sum==1&&a+b+c+d>=3) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
 } 
