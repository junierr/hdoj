#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d=0;float sum=0;
	while(scanf("%f %f %f %f",&a,&b,&c,&d)!=EOF)
	{
		sum=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		printf("%.2f\n",sum);
	}
	return 0;
}
