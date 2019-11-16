#include<stdio.h>
int main()
{
	int n,m,sum,dum;
	int a[1000];
	int b[1000];
	int c[1000];
		while(~scanf("%d %d",&n,&m))
		if(!(m==0&&n==0)){
			for(int k=0;k<1000;k++) 
			{
			  c[k]=0;a[k]=0;b[k]=0;
		    }
			sum=0;dum=1;
			for(int i=0;i<n;i++)
			 {
		        scanf("%d",&a[i]);
		        c[a[i]]=1;
		        sum++;
		     }
            for(int j=0;j<m;j++) 
			{
			   scanf("%d",&b[j]);
			   if(c[b[j]]==1) 
			   {
			      c[b[j]]=0;
			      sum--;
			    }
		     }
			 if(sum==0) printf("NULL\n");
			 else for(int y=0;y<1000;y++)
			 {
			 	if(sum!=dum&&c[y]==1) { printf("%d ",y);dum++;}
			 	else if(sum==dum&&c[y]==1) printf("%d \n",y);
			 
			 }
		     
		}	
	return 0;
	
 } 
