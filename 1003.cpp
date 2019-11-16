#include<stdio.h>
int main()
{
	int n,i,j,maxi,maxj,sum,m,now;
    long max;
	scanf("%d",&n);
    for(int l=1;l<=n;l++)
    {
    	max=-9999;sum=-9999;max=-9999;i=0;j=0;maxi=0;maxj=0;
		scanf("%d",&m);
    	for(int k=1;k<=m;k++)
    	{
    		scanf("%d",&now);
    		if(sum<0)
    		{
    		   i=k;j=k;sum=now;	
			}
			else sum=sum+now;
    		if(sum>max)
    		{
    			max=sum;
    			maxi=i;maxj=j;
			}
    		j++;
		}
		printf("Case %d:\n",l);
		if(l!=n) printf("%ld %d %d\n\n",max,maxi,maxj);
		if(l==n) printf("%ld %d %d\n",max,maxi,maxj);
	}
	return 0;
    
		
 } 
