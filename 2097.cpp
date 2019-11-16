#include<stdio.h>
int shi(int a)
{
	int ans=0;
	while(a>0)
	{
		ans+=a%10;
		a/=10;
	}
	return ans;
}
int shiliu(int a)
{
	int ans=0;
	while(a>0)
	{
		ans+=a%16;
		a/=16;
	}
	return ans;
}
int shier(int a)
{
	int ans=0;
	while(a>0)
	{
		ans+=a%12;
		a/=12;
	}
	return ans;
}


int main()
{
	int a,b,c,n;
	while(~scanf("%d",&n)&&n)
	{
		a=shi(n);
		b=shiliu(n);
		c=shier(n);
		if(a==b&&b==c) printf("%d is a Sky Number.\n",n);
		else printf("%d is not a Sky Number.\n",n);
	}
	return 0;
}
