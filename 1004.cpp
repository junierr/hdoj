#include<stdio.h>
#include<string.h>
int main()
{
	int n,t,max,sum;
	char s[1005][20];
	while(~scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
		 {
		   scanf("%s",s[i]);
		 }
	max=-1;t=0;
	for(int j=0;j<n;j++)
	 {
	 	sum=0; 
	 for(int k=j+1;k<n;k++)
	 {
	 	if(strcmp(s[j],s[k])==0) sum++;
	    if (sum>max) {
		                max=sum;
						t=j;
					 }
	 
     }
     }
	 printf("%s\n",s[t]);
	 
	 }
	 return 0;  
	 
 } 
