#include<stdio.h>
int main()
{
	int m=0,n=0,i=0,w=0,j=0;
	int q=0,sum=0,dum=0,t=0;
	int a[1000];
	while(~scanf("%d %d",&n,&m))
	{
		q=n / m;
		w= n % m;
		for(i=1;i<=n;i++)
		{
			a[i]=2*i;
	    }
		if(w!=0)
		{
		for(i=1;i<=q;i++)
	    {
	    	for(j=1;j<=m;j++)
	    	{
	    		t=t+1;
	    		sum=sum+a[t];
			}
		    dum=sum/m;
		    printf("%d ",dum);
			sum=0;
		}
		for(i=1;i<=w;i++)
		{
			sum=sum+a[m*q+i];
		}
		dum=sum/w;
		printf("%d\n",dum);
		sum=0;t=0;
        }
        if (w==0)
        {
        	for(i=1;i<=q;i++)
	    {
	    	for(j=1;j<=m;j++)
	    	{
	    		t=t+1;
	    		sum=sum+a[t];
			}
		    dum=sum/m;
		    if (i==q)
		    {
		    	printf("%d\n",dum);
			}
			if (i!=q)
			{
			  printf("%d ",dum);
		    }
			sum=0;
		}
		t=0;
		}
	}
    return 0;
}
