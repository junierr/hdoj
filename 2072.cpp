#include<bits/stdc++.h>
using namespace std;
set<string> dict;
int main()
{
	char s[1000];
	char buf[1000];
	int sum;
	while(gets(s)&&s[0]!='#')
	{
		dict.clear();
		sum=0;
		stringstream ss(s);
		while(ss>>buf) dict.insert(buf);
		for(set<string>::iterator it=dict.begin();it!=dict.end();++it)
		   sum++;
		printf("%d\n",sum);   
	}
	return 0;
}
