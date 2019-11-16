#include<stdio.h>
int main()
{
	long n;
	double a,b,c;
	while(~scanf("%ld",&n))
	{
		for(int i=0;i<n;i++)
		   {
		   	scanf("%lf%lf%lf",&a,&b,&c);
		   	if(a+b>c&&a+c>b&&b+c>a) printf("YES\n");
		   	else printf("NO\n");
		   }
	}
	return 0;
}
