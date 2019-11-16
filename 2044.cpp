#include<stdio.h>
int main()
{
	int n,a,b;
	long long f[10000];
	while(~scanf("%d",&n))
	{
		while(n--)
		{
		scanf("%d %d",&a,&b);
		for(int j=0;j<=a;j++) f[j]=0;
		f[a+1]=1;f[a+2]=2;
		if(b-a>2)
		for(int i=a+3;i<=b;i++)
		  f[i]=f[i-1]+f[i-2];
		printf("%lld\n",f[b]);  
	}
}
	return 0;
 } 
