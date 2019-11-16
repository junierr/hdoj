#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
string s[10005];

bool cmp(string a,string b)
{
	return a<b;
}

bool find(int n)
{
	int len,i,j;
	for(i=0;i<n-1;i++)
	{
		len=s[i].size();
		for(j=0;j<len;j++)
		{
			if(s[i][j]!=s[i+1][j])
			  break;
		}
		if(j==len)
		  return true;
		  
	}
	return false;
}


int main()
{
	int n,t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
        {
        	cin>>s[i];
		}
    sort(s,s+n,cmp);
    if(find(n))
      printf("NO\n");
    else 
	  printf("YES\n");  
	}
}
