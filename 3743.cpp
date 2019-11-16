#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long c[1000005];
long long n;
struct pp
{
	long long num;
	long long id;
}a[1000005];

bool cmp(pp x,pp y)
{
	return x.num<y.num;
}
int lowbit(int x)
{
	return (x&(-x));
}

void update(long long x,long long y)
{
	for(;x<=n;c[x]+=y,x+=lowbit(x));
}

int sum(long long x)
{
	int ret=0;
	for(;x>0;ret+=c[x],x-=lowbit(x));
	return ret;
}
int main()
{
	long long ans,i;
	while(~scanf("%lld",&n))
	{
		memset(c,0,sizeof(c));
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].num);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++)
		{
			update(a[i].id,1);
			ans+=i-sum(a[i].id);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
