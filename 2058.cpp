//差值遍历(a+...+a+k-1)，公式：1+2+3+。。。+(int)根号2m<m; 
#include<stdio.h>
#include<math.h>
int main()
{
	double n,m;
	double a;
	while(~scanf("%lf%lf",&n,&m)&&n&&m)
	{
		for(long long i=(int)sqrt(2*m);i>0;i--)
		{
			a=(2*m/i-i+1)/2;
		   if((long long)a==a) 
		   	 printf("[%lld,%lld]\n",(long long)a,(long long)a+i-1);
	    }
	printf("\n");
    }
	return 0;
}
