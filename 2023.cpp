#include<stdio.h>
int main()
{
	int m,n,sum=0,dum=0,num=0,judge=0;
	int a[100][100];
	double b[100],c[100];
	while(~scanf("%d %d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				dum=dum+a[i][j]; 	
			}
			b[i]=dum/(m*1.0);dum=0;
		}
		for(int k=1;k<=m;k++)
		{
			for(int l=1;l<=n;l++)
			{
				num=num+a[l][k];
			}
			c[k]=num/(n*1.0);num=0;
		}
		for(int o=1;o<=n;o++)
		{
  		   for(int p=1;p<=m;p++)
  		   {
  		   	  if(a[o][p]<c[p]) judge=1;
		   }
		   if(judge==0) sum=sum+1;
		   judge=0;
		}
		for(int x=1;x<=n;x++) 
		{
		  if(x!=n)printf("%.2lf ",b[x]);
		  if(x==n)
		  {
		    printf("%.2lf",b[x]);
			printf("\n");
		  }
	    }
		for(int y=1;y<=m;y++)
		{
		  if(y!=m)printf("%.2lf ",c[y]);
		  if(y==m)
		  {
		    printf("%.2lf",c[y]);
			printf("\n");
		  }
	    }
		printf("%d\n",sum);sum=0;printf("\n");
	}
	return 0;
 } 
