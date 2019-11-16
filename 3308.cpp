/*
线段树区间合并 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct pp
{
	int l,r;//左区间，右区间 
	int lsum,rsum,sum;//区间左端点开始最长序列，区间右端点结束最长序列 
	int ls,rs;//左右边界值 
}tree[100005<<2];

int a[100005];


void pushup(int rt)
{
	tree[rt].ls=tree[rt<<1].ls;
	tree[rt].rs=tree[rt<<1|1].rs;
	tree[rt].lsum=tree[rt<<1].lsum;
	tree[rt].rsum=tree[rt<<1|1].rsum;
	tree[rt].sum=max(tree[rt<<1].sum,tree[rt<<1|1].sum);
	if(tree[rt<<1].rs<tree[rt<<1|1].ls)
	{
		if(tree[rt<<1].lsum==tree[rt<<1].r-tree[rt<<1].l+1)
	      tree[rt].lsum+=tree[rt<<1|1].lsum;
		if(tree[rt<<1|1].rsum==tree[rt<<1|1].r-tree[rt<<1|1].l+1)
		  tree[rt].rsum+=tree[rt<<1].rsum;
		tree[rt].sum=max(tree[rt].sum,tree[rt<<1].rsum+tree[rt<<1|1].lsum);  
	}
}


void build(int l,int r,int rt)
{
	tree[rt].l=l;
	tree[rt].r=r;
	if(l==r)
	{
		tree[rt].lsum=tree[rt].rsum=tree[rt].sum=1;
		tree[rt].ls=tree[rt].rs=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

int query(int l,int r,int rt)
{
	if(tree[rt].l>=l&&tree[rt].r<=r)
	{
		return tree[rt].sum;
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	int ans=0;
	if(l<=mid)
	  ans=max(ans,query(l,r,rt<<1));
	if(r>mid) 
	  ans=max(ans,query(l,r,rt<<1|1));
	if(tree[rt<<1].rs<tree[rt<<1|1].ls)
	  ans=max(ans,min(tree[rt<<1].rsum,mid-l+1)+min(tree[rt<<1|1].lsum,r-mid));
	return ans;       
}

void update(int rt,int L,int c)
{
	if(tree[rt].l==tree[rt].r)
	{
		tree[rt].ls=tree[rt].rs=c;
		return;
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(L<=mid) update(rt<<1,L,c);
	else update(rt<<1|1,L,c);
	pushup(rt);
}

int main()
{
	int T,n,m,x,y,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		build(1,n,1);  
		for(i=1;i<=m;i++)
		{
			char s[10];
			scanf("%s%d%d",s,&x,&y);
			if(s[0]=='U')
			{
				x++;
				update(1,x,y);
			}
			else if(s[0]=='Q')
			{
				x++;y++;
				printf("%d\n",query(x,y,1));
			}
		}
	}
	return 0;
} 
