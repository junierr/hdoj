#include<bits/stdc++.h>
using namespace std;
long long s[10005];
long long find(long long x)
{
	long long r=x;
	while(s[r]!=r) 
	{
		r=s[r];
	}
	return r;
}
void hb(long long x,long long y)
{
	if(x!=y) s[x]=y;
 } 


int main()
{
	long long sum,n,m,i,fx,fy,x,y;
	while(cin>>n>>m,n)
	{
		for(i=1;i<=n;i++) s[i]=i;
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			fx=find(x);
			fy=find(y);
			hb(fx,fy);
		}
		sum=-1;
		for(i=1;i<=n;i++)
		{
			if(s[i]==i) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
