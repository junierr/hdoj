#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int max=' ';
	while(~scanf("%s",a))
	{
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]>max) max=a[i];
		}
		for(int j=0;j<strlen(a);j++)
		{
			  if(a[j]!=max) printf("%c",a[j]);
			  if(a[j]==max) printf("%c(max)",a[j]);
	    }
	    printf("\n");
		max=' ';
    } 
    return 0;
}
