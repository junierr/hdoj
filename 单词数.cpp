#include<cstdio>
#include<string>
#include<set>
#include<cstring>
using namespace std;
set<string> dd;
int main()
{
	char s[100000];
	string a,b;
	int i,len,p,sum,q;
	while(gets(s))
	{
		a=s;
		dd.clear();
		if(a[0]=='#') break;
		else if(a[0]=='\0') 
		{
			printf("0\n");
			continue;
		}
	    i=0;len=0;
		while(a[i]==' ') i++;
		for(i;i<strlen(s)+1;i++)
		{
			if(a[i]>='a'&&a[i]<='z') 
			{
                len++;
                q=0;
            }
            else 
			{
                if(q==0)
				{
					p=i-len;
					b=a.substr(p,len);
					dd.insert(b);
					len=0;
					q=1;
				}
            }
		}
		sum=0;
		for(set<string>::iterator it=dd.begin();it!=dd.end();it++)
		  sum++;
		printf("%d\n",sum);      
	}
	return 0;
}

