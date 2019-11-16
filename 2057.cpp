#include <stdio.h>
int main()
{
    long long i,a,b,sum;
    while(~scanf("%I64X %I64X",&a,&b))
	{
        sum = a+b;
        if(sum >= 0)
		{
            printf("%I64X\n",sum);
        }
		else
		{
            sum = -sum;
            printf("-%I64X\n",sum);
        }
    }
}
