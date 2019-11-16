#include<bits/stdc++.h>
using namespace std;
long long a[10000];
long long find(long long x)
{
	long long r=x;
	while(a[r]!=r)
	{
		r=a[r];
	}
	return r;
}
void hb(long long x,long long y)
{
	if(x!=y) a[x]=y; 
 } 

int main()
{
	long long t,sum,i,n,m,x,y,hx,hy;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int();
		sum=0;
		for(i=1;i<=n;i++) a[i]=i;
		for(i=1;i<=m;i++) 
		{
			cin>>x>>y;
			hx=find(x);
			hy=find(y);
			hb(hx,hy);
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]==i) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
