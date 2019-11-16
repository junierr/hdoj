#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,m,n;
	cin>>c;
	while(c--)
	{
		cin>>n>>m;
		if(n<=m) 
		{
			cout<<"Grass"<<endl;
			continue;
		}
		else
		{
			if(n%(m+1)==0)
			  cout<<"Rabbit"<<endl;
			else
			  cout<<"Grass"<<endl; 
		}
	}
	return 0;
} 
