#include<cstdio>
#include<cstring>
using namespace std;
int a[32005],c[32005];
int lowbit(int x)
{
	return (x&(-x));
}

void update(int x,int y)
{
	for(;x<32005;x+=lowbit(x))
	  c[x]+=y;
}

int sum(int x)
{
	int ret=0;
	for(;x>0;x-=lowbit(x))
	  ret+=c[x];
	return ret;  
}
int main()
{
	int n,i,x,y;
	while(~scanf("%d",&n))
	{
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			x++;
			a[sum(x)]++;
			update(x,1);
		}
		for(i=0;i<n;i++)
		  printf("%d\n",a[i]);
	}
	return 0;
 } 
