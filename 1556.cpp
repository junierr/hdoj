#include<cstdio>
#include<cstring>
using namespace std;

int tree[100005];
int n;

int lobit(int x)
{
	return x&(-x);
}

int sum(int x)
{
	int ret=0;
	for(;x>0;ret+=tree[x],x-=lobit(x));
	return ret;
}

void update(int x,int y)
{
	for(;x<=n;tree[x]+=y,x+=lobit(x));
}

int main()
{
	int i,a,b;
	while(~scanf("%d",&n)&&n)
	{
		memset(tree,0,sizeof(tree));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			update(a,1);
			update(b+1,-1);
		}
	    for(i=1;i<n;i++)
		  printf("%d ",sum(i));
		printf("%d\n",sum(n));  	
	}
	return 0;
 } 
