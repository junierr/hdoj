#include<cstdio>
#include<cstring>
using namespace std;
struct mar
{
	long long m[30][30];
}res,ans;
long long sum,n,m;

mar mul(mar a,mar b)
{
	mar tmp;
	long long i,j,k;
	for(i=1;i<=sum;i++)
	  for(j=1;j<=sum;j++)
	    tmp.m[i][j]=0;
	for(i=1;i<=sum;i++)
	  for(j=1;j<=sum;j++)
	    for(k=1;k<=sum;k++)
		  tmp.m[i][j]+=a.m[i][k]*b.m[k][j];
	return tmp;	      
}



void quick(long long p)
{
	long long i;
	mar gg=res;
	memset(ans.m,0,sizeof(ans.m));
	for(i=1;i<=sum;i++)
		  ans.m[i][i]=1;
	while(p)
	{
		if(p&1)
		  ans=mul(ans,gg);
		gg=mul(gg,gg);
		p=p>>1;  
	}
	if(ans.m[1][sum]==0)
	  printf("False\n");
	else 
	{
		int flag=0;
		for(i=1;i<sum;i++)
		  if(ans.m[1][i]!=0)
		  {
		  	flag=1;
		  	break;
		  }
		if(flag==0)
		  printf("True\n");
		else 
		  printf("Maybe\n");    
	}  
}


int main()
{
	long long t,i,j,x1,x2,y1,y2,x3,x4,y3,y4,p,q;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&m,&n);
		getchar();
		sum=n*m;
		memset(res.m,0,sizeof(res.m));
		for(i=1;i<=m;i++)
		  for(j=1;j<=n;j++)
		  {
		  	scanf("((%lld,%lld),(%lld,%lld),(%lld,%lld),(%lld,%lld))",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		  	getchar();
			if(i==m&&j==n) continue;
		  	res.m[(i-1)*n+j][(x1-1)*n+y1]=1;
		  	res.m[(i-1)*n+j][(x2-1)*n+y2]=1;
		  	res.m[(i-1)*n+j][(x3-1)*n+y3]=1;
		  	res.m[(i-1)*n+j][(x4-1)*n+y4]=1;
		  }
		scanf("%lld",&q);  
		while(q--)
		{
			scanf("%lld",&p);
			quick(p);
		}
		printf("\n");
	}
	return 0;
} 
