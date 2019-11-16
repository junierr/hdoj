#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
using namespace std;
map<string,int> m;
char s[100005][100];
int main()
{
	char f[100];
	char q[100];
	int k=0,i,j,l1,l2;
	m.clear();
	while(cin>>s[k])
	{
		m[s[k]]=1;
		k++;
	}
	for(i=0;i<k;i++)
	{
		for(j=0;s[i][j];j++)
		{
			f[j]=s[i][j];
			f[j+1]='\0';
			if(m[f]==1)
			{
				for(l1=j+1,l2=0;s[i][l1];l1++,l2++)
				  q[l2]=s[i][l1];
				q[l2]='\0';
				if(m[q]==1)
				{
					cout<<s[i]<<endl;
					break;
				  }  
			}
		}
	 }
	 return 0; 
}
