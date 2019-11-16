#include<stdio.h>
#include<math.h>
int main()
{
	double r,v,q=0;
	while(~scanf("%lf",&r))
	{
	
	q=pow(r,3);
	v=3.1415927*q*4/3;
	printf("%.3lf\n",v);
 } 
 return 0 ;
 }
