#include<cstdio>
using namespace std;
struct mac
{
	int m[2][2];
}ans,res;

mac mul(mac a, mac b)
{
	int i,j,k;
	mac tmp;
	for(i=0;i<2;i++)
	  for(j=0;j<2;j++)
	    tmp.m[i][j]=0;
	for(i=0;i<2;i++)
	  for(j=0;j<2;j++)
	    for(k=0;k<2;k++)
		  {
		    tmp.m[i][j]+=a.m[i][k]*b.m[k][j]%10000;
		    tmp.m[i][j]=tmp.m[i][j]%10000;
		  }
	return tmp;	     
}



void quickpower(int n)
{
	n=n-1;
	while(n)
	{
		if(n&1)
		{
			ans=mul(ans,res);
		}
		res=mul(res,res);
		n=n>>1;
	}
	printf("%d\n",ans.m[0][0]);
	return;
}
int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		if(n==-1) break;
		if(n==0) 
		{
			printf("0\n");
			continue;
		}
		else 
		{
			ans.m[0][0]=1;ans.m[1][1]=1;
			ans.m[0][1]=0;ans.m[1][0]=0;
			res.m[0][0]=1;res.m[0][1]=1;
			res.m[1][0]=1;res.m[1][1]=0;
			quickpower(n);
		}
			
	}
	return 0;
}
