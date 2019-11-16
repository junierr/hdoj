#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,s[100000],i,k;
	while(~scanf("%d%d",&n,&m))
	{
		k=0;
		for(i=1;i<=n;i++) scanf("%d",&s[k++]);
		for(i=1;i<=m;i++) scanf("%d",&s[k++]);
		sort(s,s+k);
		for(i=0;i<k;i++)
		{
			if(i==0) 
			{
				printf("%d",s[0]);
			}
			else if(s[i]!=s[i-1])
			{
				printf(" %d",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
