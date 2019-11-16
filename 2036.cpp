#include<stdio.h>
double ares(int a,int b,int c,int d,int e,int f)
{
	return 0.5*(f*c+a*d+e*b-f*a-b*c-e*d);
}
int main()
{
	int n,x[101],y[101];
	double s=0;
	while(~scanf("%d",&n)&n)
	{
		s=0;
		for(int i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		for(int i=2;i<n;i++)
			s+=ares(x[0],y[0],x[i-1],y[i-1],x[i],y[i]);
		printf("%0.1lf\n",s);
	}
	return 0; 
}
