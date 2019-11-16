#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,num1,num2,sum,ans,t;
	cin>>n;
	while(n--)
	{
		cin>>num1>>num2;
		ans=0;
		if(num1>num2)
		{
			t=num1;num1=num2;num2=t;
		}
		for(long long i=num1;i<=num2;i++)
		{
		   sum=1;
		   for(long long j=2;j<=i/2;j++)
		   {
		   	  if(i % j==0) sum+=j;
			}
			if(sum==i) ans++;	
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
