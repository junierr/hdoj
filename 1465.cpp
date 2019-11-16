#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,f[100000];
	while(cin>>n)
	{
	f[1]=0;f[2]=1;f[3]=2;
	for(long long i=4;i<=n;i++) 
	  f[i]=(i-1)*(f[i-1]+f[i-2]);
	cout<<f[n]<<endl;
}
	return 0;  
	
 } 
