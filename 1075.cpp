#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,string> m;
int main()
{
	string a,b;
	int len,i;
	cin>>a;
	while(cin>>a&&a!="END")
	{
		cin>>b;
		m[b]=a;
	}
	cin>>a;
	getchar();
	char s[10005];
	while(true)
	{
		gets(s);
		if(strcmp(s,"END")==0)
		  break;
		len=strlen(s);
		b="";
		for(i=0;i<len;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			  b+=s[i];
			else
			{
				if(m.find(b)!=m.end())
				  cout<<m[b];
				else cout<<b;
				b="";
				cout<<s[i]; 
			}  
		}
		cout<<endl;  
	}
	return 0;
}
