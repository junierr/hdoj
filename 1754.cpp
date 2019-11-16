#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pp
{
	int val;
}tree[800005];
int a[200005];

void pushup(int rt)
{
	tree[rt].val=max(tree[rt<<1].val,tree[rt<<1|1].val);
}

void build(int l,int r,int rt)
{
	if(l==r) 
	{
		tree[rt].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

void update(int L,int c,int l,int r,int rt)
{
	if(l==r)
	{
		tree[rt].val=c;
	    return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(L,c,l,mid,rt<<1);
	else update(L,c,mid+1,r,rt<<1|1);
	pushup(rt);
}


int qurry(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return tree[rt].val;
	}
	if(L>r||R<l)
	{
		return 0;
	}
	int mid=(l+r)>>1;
	return max(qurry(L,R,l,mid,rt<<1),qurry(L,R,mid+1,r,rt<<1|1)); 
}

int main()
{
	int n,m,i,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		build(1,n,1);
		for(i=1;i<=m;i++)
		{
			char c[5];
			scanf("%s",c);
			if(c[0]=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",qurry(x,y,1,n,1));
			}
			else if(c[0]=='U')
			{
				scanf("%d%d",&x,&y);
				update(x,y,1,n,1);
			}
		}  
	}
	return 0;
 } 
