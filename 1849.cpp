#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,i,t,k[10000];
	while(~scanf("%d",&m)&&m)
	{
		t=0;
		for(i=0;i<m;i++) 
		{
		   scanf("%d",&k[i]);
	       t^=k[i];
		}
		if(t) printf("Rabbit Win!\n");
		else printf("Grass Win!\n");
		 
	}
	return 0;
}
