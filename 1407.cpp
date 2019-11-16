#include<bits/stdc++.h>
using namespace std;
int main()
{
	int flag,n,i,j,k;
    while(cin>>n)
	{
		flag=0;
		for( i=1;i<=sqrt(n);i++)
		{
			for( j=1;j*j<=n-i;j++)
			{
				for(k=1;k*k<=n-i-j;k++)
				{
					if(i*i+j*j+k*k==n)
					{
						flag=1;
						break;
					}
				}
				if(flag==1) break;
			}
			if(flag==1) break;
		}
		cout<<i<<" "<<j<<" "<<k<<endl;
	}
	return 0;
 } 
