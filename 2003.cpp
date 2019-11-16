#include<stdio.h>
int main()
{
	double n=0;
	while(~scanf("%lf",&n)){
		if(n<0){
			n=0-n;
		}
		printf("%.2lf\n",n);
	}
	return 0;

}
