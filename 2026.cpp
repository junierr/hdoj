#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	while(gets(s))
	{
		if('a'<=s[0]<='z') s[0]=s[0]-32;
		for(int i=1;s[i]!='\0';i++)
		{
			if('a'<=s[i]<='z'&&s[i-1]==' ') s[i]=s[i]-32;
		}
		puts(s);
	}
	return 0;
 } 
