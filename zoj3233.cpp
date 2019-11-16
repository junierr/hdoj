#include<cstdio>
using namespace std;
struct mar
{
	int m[100][100];
}ans,res;
int m,n;

mar mul(mar a,mar b)
{
	mar tmp;
	int i,j,k;
	for(i=1;i<=2*n;i++)
	  for(j=1;j<=2*n;j++)
	    tmp.m[i][j]=0;
	for(i=1;i<=2*n;i++)
	  for(j=1;j<=2*n;j++)
	    for(k=1;k<=2*n;k++)
		  tmp.m[i][j]=(tmp.m[i][j]%m+a.m[i][k]*b.m[k][j]%m)%m;    
	return tmp;    
}


void quick(int now)
{
	int i,j;
	while(now)
	{
		if(now&1)
		  ans=mul(ans,res);
		res=mul(res,res);
		now>>=1;  
	}
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
	  	if(j==n)
	  	  printf("%d\n",ans.m[i][j]%m);
	  	else printf("%d ",ans.m[i][j]%m);  
	  }
	return;  
}




int main()
{
	int k,i,j;
	scanf("%d%d%d",&n,&k,&m);
	  for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
		  scanf("%d",&res.m[i][j]);
		  ans.m[i][j]=res.m[i][j];
		  if(i==j) ans.m[i][j+n]=1;
		    else ans.m[i][j+n]=0;
		  res.m[i+n][j]=res.m[i][j];
		  res.m[i][j+n]=0;
		  if(i==j) res.m[i+n][j+n]=1;
		    else res.m[i+n][j+n]=0;   
		}
	if(k==1) 
	  {
	  	for(i=1;i<=n;i++)
	      for(j=1;j<=n;j++)
	      {
	  	    if(j==n)
	  	      printf("%d\n",ans.m[i][j]%m);
	  	    else printf("%d ",ans.m[i][j]%m);  
	      }
	  }	
	else quick(k-1);	
	return 0;	
} 
