#include<stdio.h>
int main()
{
	long m,a,b,sum1,sum2;
	while(~scanf("%ld",&m))
	{
		for(long k=0;k<m;k++)
		{
		  scanf("%ld%ld",&a,&b);
		  sum1=0;sum2=0;
		  for(long i=1;i<a;i++)
	      {
	      	 if(a%i==0) sum1+=i; 
		  }
		  for(long j=1;j<b;j++)
		  {
		  	if(b%j==0) sum2+=j;
		  }
		  if(sum1==b&&sum2==a) printf("YES\n");
		  else printf("NO\n");
	    }
	}
	return 0;
 } 
