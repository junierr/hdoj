#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,j,t,n,v,f[1005],a[1005],b[1005];
	cin>>t;
	while(t--)
	{
		cin>>n>>v;
		f[0]=0;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) cin>>b[i];
		for(i=0;i<=v;i++)  f[i]=0;
		for(i=1;i<=n;i++)
		{
			for( j=v;j>=0;j--)
			{
				if(b[i]<=j) f[j]=max(f[j],f[j-b[i]]+a[i]);
			}
		}
		cout<<f[v]<<endl;
	}
	return 0;
} 
