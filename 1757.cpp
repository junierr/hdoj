#include<cstdio>
using namespace std;
struct mar
{
	long long m[10][10];
}ans,res;
long long m;

mar mul(mar a,mar b)
{
	mar tmp;
	long long i,j,l;
	for(i=0;i<10;i++)
	  for(j=0;j<10;j++)
	    tmp.m[i][j]=0;
	for(i=0;i<10;i++)
	  for(j=0;j<10;j++)
	    for(l=0;l<10;l++)
		{
			tmp.m[i][j]=tmp.m[i][j]%m+a.m[i][l]*b.m[l][j]%m;
		}
	return tmp;	    
}

void quick(long long n)
{
	while(n)
	{
		if(n&1) 
		  ans=mul(res,ans);
		res=mul(res,res);
		n=n>>1;
	}
	printf("%lld\n",ans.m[0][0]%m);
}


int main()
{
	long long k,i,j;
	while(~scanf("%lld%lld",&k,&m))
	{
		for(i=0;i<10;i++)
		  for(j=0;j<10;j++)
		  {
			ans.m[i][j]=0;
			res.m[i][j]=0;
		  }
		for(i=0;i<10;i++)
		  scanf("%lld",&res.m[0][i]);
		for(i=1;i<10;i++)
		  res.m[i][i-1]=1;  
		if(k<10)
		{
			printf("%lld\n",k%m);
			continue;
		}
		ans.m[0][0]=9;
		ans.m[1][0]=8;
		ans.m[2][0]=7;
		ans.m[3][0]=6;
		ans.m[4][0]=5;
		ans.m[5][0]=4;
		ans.m[6][0]=3;
		ans.m[7][0]=2;
		ans.m[8][0]=1;
		ans.m[9][0]=0;
		quick(k-9);  
	}
	return 0;
} 
