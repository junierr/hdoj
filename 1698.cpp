#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

struct pp
{
	long long val;
	long long lazy;
}tree[400005];


void pushup(long long rt)
{
	tree[rt].val=tree[rt<<1].val+tree[rt<<1|1].val;
}

void pushdown(long long rt,long long ln,long long rn)
{
	if(tree[rt].lazy)
	{
	tree[rt<<1].lazy=tree[rt].lazy;
	tree[rt<<1|1].lazy=tree[rt].lazy;
	tree[rt<<1].val=tree[rt].lazy*ln;
	tree[rt<<1|1].val=tree[rt].lazy*rn;
	tree[rt].lazy=0;
    } 
}

void build(long long l,long long r,long long rt)
{
	tree[rt].lazy=0;
	if(l==r)
	{
		tree[rt].val=1;
		return;
	}
	long long m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(long long L,long long R,long long c,long long l,long long r,long long rt)
{
	if(L<=l&&r<=R)
	{
		tree[rt].val=c*(r-l+1);
		tree[rt].lazy=c;
		return;
	}
	long long m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m) update(L,R,c,l,m,rt<<1);
	if(R>m) update(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
}
int main()
{
	long long T,i,j,x,z,y,q,n;
	scanf("%lld",&T);
	for(j=1;j<=T;j++)
	{
		memset(tree,0,sizeof(tree));
		scanf("%lld",&n);
		build(1,n,1);  
		scanf("%lld",&q);
		while(q--)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			update(x,y,z,1,n,1);
		}
		printf("Case %lld: The total value of the hook is %lld.\n",j,tree[1].val);
	}
	return 0;
}
