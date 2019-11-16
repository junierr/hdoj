#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,last,i,t;
	long long k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		int last=0;
		for(i=2;i<=n;i++)
		{
			last=(last+k)%i;
		}
		printf("%d\n",last+1);
	}
	return 0;
 } 
