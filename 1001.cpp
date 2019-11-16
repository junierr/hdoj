#include<stdio.h>
int main()
{
	int  a,sum=0;int i=1;
	while(scanf("%d",&a)!=EOF){
		for(i=1;i<=a;i++)
			sum+=i; 
		
	
	    printf("%d\n\n",sum);
	    sum=0;
}
	return 0;
}
