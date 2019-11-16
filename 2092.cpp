#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t,i,mm,count;
	int a[10000],b[10000];
	while(~scanf("%d%d",&n,&m))
	{
		if(m==0&&n==0) break;
		count=0;
		mm=abs(m);
		for(i=1;i<mm/2;i++)
		{
			if(mm%i==0)
			{
				a[count]=i;b[count]=mm/i;
				count++;
			}
		}
		t=0;
		for(i=0;i<count;i++)
		{
			if(a[i]+b[i]==n) 
			{
				t=1;
				break;
			}
		}
		if(t==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
