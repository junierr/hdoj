#include<cstdio>
#include<cstring>
using namespace std;
struct mac
{
	long long m[15][15];
}ans,res;
int n;
long long k;

mac mul(mac a,mac b)
{
	int i,j,l;
	mac tmp;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    tmp.m[i][j]=0;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    for(l=0;l<n;l++)
	    {
	    	tmp.m[i][j]+=a.m[i][l]*b.m[l][j];
	    	tmp.m[i][j]%=9973;
		}
	return tmp;	
}


void quick()
{
	int i,j;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
	  	if(i==j) ans.m[i][j]=1;
	  	else ans.m[i][j]=0;
	  }
	while(k)
	{
		if(k&1)
		  ans=mul(ans,res);
		res=mul(res,res);
		k=k>>1;  
	}
    long long sum=0;
	for(i=0;i<n;i++)
	{
		sum+=ans.m[i][i];
		sum%=9973;
	}
	printf("%lld\n",sum);
	return;  
}


int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		    scanf("%lld",&res.m[i][j]);
		quick();    
	}
	return 0;
}
