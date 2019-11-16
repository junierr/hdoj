#include<cstdio>
#include<cstring>
using namespace std;

struct pp
{
	int val;
	
 }tree[55][200005];
 
int aa[50005];
int lo[11];
int mark[200005]; 
void pushdown(int rt)
{
    if(mark[rt])
	{
		mark[rt<<1]=mark[rt<<1|1]=mark[rt];
		for(int i=0;i<55;i++)
		{
	    	tree[i][rt<<1].val+=tree[i][rt].val;
	    	tree[i][rt<<1|1].val+=tree[i][rt].val;
	    	tree[i][rt].val=0;
	    }
	    mark[rt]=0;
	}
}

void update(int a,int b,int k,int c,int l,int r,int rt)
{
	if(l>=a&&b>=r)
	{
		int t=lo[k-1]+a%k;
		mark[rt]=1;
		tree[t][rt].val+=c;
		return;
	}
	int m=(l+r)>>1;
	if(m>=a)
	  update(a,b,k,c,l,m,rt<<1);
	if(m<b) 
	  update(a,b,k,c,m+1,r,rt<<1|1);     
} 

void build(int l,int r,int rt)
{
	for(int i=0;i<55;i++)
	  tree[i][rt].val=0;
	mark[rt]=0;  
	if(l==r)
	{
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
}

int query(int L,int l,int r,int rt)
{
	if(l==r)
	{
		int ans=0;
		for(int i=1;i<=10;i++)
		  ans+=tree[i%L+lo[i-1]][rt].val;
		return ans;  
	}
	int m=(l+r)>>1;
	pushdown(rt);
	if(m>=L)
        return query(L,l,m,rt<<1);
    else 
        return query(L,m+1,r,rt<<1|1); 
}

int main()
{
    int n,a,b,c,k,x,t,tt;
	lo[0]=0;	
	for(int i=1;i<=10;i++)
	  lo[i]=i+lo[i-1];
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		  scanf("%d",&aa[i]);
		build(1,n,1);  
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&tt);
			if(tt==1) 
			{
				scanf("%d%d%d%d",&a,&b,&k,&c);
				update(a,b,k,c,1,n,1);
			}
			else
			{
				scanf("%d",&x);
				printf("%d\n",query(x,1,n,1)+aa[x]);
			 } 
		}  
	}
	return 0;
}  
