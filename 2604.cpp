#include<cstdio>
#include<cmath>
using namespace std;
struct maxtrix
{
	long long m[4][4];
}ans,res;
long long m,l;
maxtrix mul(maxtrix b,maxtrix a)
{
	long long i,j,k;
	maxtrix tmp;
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	    tmp.m[i][j]=0;
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
		for(k=0;k<4;k++)
		    tmp.m[i][j]=(tmp.m[i][j]%m+a.m[i][k]*b.m[k][j])%m;	
	return tmp;	      
}

void quickpower(long long n)
{
	long long i,j;
	while(n)
	{
		if(n&1)
	      ans=mul(ans,res);
	    res=mul(res,res);
		n=n>>1;  
	}
	printf("%lld\n",ans.m[0][0]%m);
}
int main()
{
	while(~scanf("%lld%lld",&l,&m))
	{
		if(l<=4)
		{
		  if(l==0) printf("0\n");
		  else if(l==1) printf("%lld\n",2%m);
		  else if(l==2) printf("%lld\n",4%m);
		  else if(l==3) printf("%lld\n",6%m);
		  else if(l==4) printf("%lld\n",9%m);
		  continue;
	    }
		long long i,j;
		for(i=0;i<4;i++)
		   for(j=0;j<4;j++)
		   {
		   	 ans.m[i][j]=0;
		   	 res.m[i][j]=0;
		   }   
		ans.m[0][0]=9;
		ans.m[1][0]=6;
		ans.m[2][0]=4;
		ans.m[3][0]=2;
		res.m[0][0]=1;
		res.m[1][0]=1;
		res.m[2][1]=1;
		res.m[0][2]=1;
		res.m[0][3]=1;
		res.m[3][2]=1;
		quickpower(l-4);    
	}
	return 0;
} 
