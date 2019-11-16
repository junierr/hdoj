#include<bits/stdc++.h>
using namespace std;
set<int> dict;
int main()
{
	int n,m,i,x;
	while(~scanf("%d%d",&n,&m))
	{
		dict.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			dict.insert(x);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			dict.insert(x);
		}
		for(set<int>::iterator it=dict.begin();it!=dict.end();++it )
		  if(it==dict.begin()) printf("%d",*it);
		  else printf(" %d",*it);
		  printf("\n");
	}
	return 0;
}
