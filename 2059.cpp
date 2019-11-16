#include<stdio.h>
int main()
{
	long long i,j;
	double l,n,len,c,t,vr,v1,v2;
	double time1,time2,p1,p2;
	double a[1000];
	double b[1000];
	while(~scanf("%lf",&l))
	{
		scanf("%lf%lf%lf",&n,&c,&t);
		scanf("%lf%lf%lf",&vr,&v1,&v2);
		for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
		a[0]=0;a[(int)n+1]=l;
		time1=l/(vr*1.0);
        for( i=1;i<=n+1;i++) b[i]=99999;
        b[0]=0;
		for( i=1;i<=n+1;i++)
        {
        	for(j=0;j<i;j++)
        	{
        		len=a[i]-a[j];
        		if(c>=len) time2=len/v1;
        		else time2=c/v1+(len-c)/v2;
        		time2+=b[j];
        		if(j!=0) time2+=t;//假设 a[j]为起点，要先充电； 
        		if(b[i]>time2) b[i]=time2;
			}
		}
		if(b[(int)n+1]<time1) printf("What a pity rabbit!\n");
		else printf("Good job,rabbit!\n");
	} 
	 return 0;
}
