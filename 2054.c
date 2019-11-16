#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s1[100000],s2[100000],b1[10000],b2[100000],c1[100000],c2[100000];
	long a1,a2,i,j,num,strb1,strb2,strc1,strc2,n,t;
	while(~scanf("%s%s",s1,s2))
	{
		a1=strlen(s1);a2=strlen(s2);
		num=0,strb1=0,strb2=0,strc1=0,strc2=0;n=0;i=0;
		if(s1[0]=='+'&&s2[0]!='-') i++;
		else if(s1[0]=='-'&&s2[0]=='-') i++;
		else if(isdigit(s1[0])==1&&s2[0]=='+') i=0;
		else if(isdigit(s1[0])==0||isdigit(s2[0])==0) 
		{
			printf("NO\n");
			continue;
		}
		for(i;i<a1&&s1[i]!='.';i++)
		{
			if(s1[i]!='0') num++;
			if(num>0)
			{
				b1[n]=s1[i];
				n++;
			}
		}
	    if(num>0) strb1=n;
		num=0;n=0;
		if(i<a1-1)
		{
		for(j=a1-1;j>=i+1;j--)
		{
			if(s1[j]!='0') num++;
        	if(num>0)
			{
				b2[n]=s1[j];
				n++;
			}
		}
			if(num>0) strb2=n;
		}
		num=0;n=0;i=0;
		if(isdigit(s2[0])==0) i++;
		for(i;i<a2&&s2[i]!='.';i++)
		{
			if(s2[i]!='0')	num++;
			if(num>0)
			{
				c1[n]=s2[i];
				n++;
			}
		}
		if(num>0)	strc1=n;
		num=0;
		n=0;
		if(i<a2-1)
		{
		for(j=a2-1;j>=i+1;j--)
		{
			if(s2[j]!='0')	num++;	
			if(num>0)
			{
				c2[n]=s2[j];
				n++;
			}	
		}
		}
		if(num>0) strc2=n;
		num=0;n=0;
		if((strb1==strc1)&&(strb2==strc2))
		{
			for(i=0;i<strb1;i++)	
				if(b1[i]!=c1[i])
				{
					num++;
					break;
				}
			for(i=0;i<strb2;i++)
				if(b2[i]!=c2[i])
				{
					num++;
					break;
				}
			if(num==0)	printf("YES\n");
			else printf("NO\n");
	    }
	else printf("NO\n");
	}
	return 0;
}
