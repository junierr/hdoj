#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,n,m,i,j,sum;
	int a[10000]={0};
	cin>>c;
	while(c--)
	{
		cin>>n>>m;
		for(i=1;i<=m;i++) a[i]=1;
		for(i=m+1;i<=n;i++)
		{
			sum=0;
			for(j=1;j<=m;j++)
			{
				if(a[i-j]==1) sum++;
			}
			if(sum==m) a[i]=0;
			else a[i]=1;
		}
		if(a[n]==1) cout<<"first"<<endl;
		else cout<<"second"<<endl;
	}
	return 0;
}
