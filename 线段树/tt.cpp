/*
按r从小到大做，贪心，每次如果区间内1的数量不够就往后放
操作用线段树 
二分查找从哪开始放1 
*/ 

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define N 500005
using namespace std;

int number[N<<2],bz[N<<2];
struct pp{
	int l,r,val;
}a[N<<1];

bool cmp(pp x,pp y){
	return x.r<y.r;
}

void pushdown(int rt){
	if(bz[rt]){
		number[rt*2]=0;
		number[rt*2+1]=0;
		bz[rt*2]=1;
		bz[rt*2+1]=1;
		bz[rt]=0;
	}
}

void pushup(int rt){
	number[rt]=number[rt*2]+number[rt*2+1];
}

void ins(int rt,int L,int R,int l,int r){
	if(L<=l&&r<=R){
		number[rt]=0;
		bz[rt]=1;
		return;
	}
	int mid=(l+r)/2;
	pushdown(rt);
	if(L<=mid) ins(rt*2,L,R,l,mid);
	if(R>mid) ins(rt*2+1,L,R,mid+1,r);
	pushup(rt);
}


int query(int rt,int L,int R,int l,int r){//区间和 
	if(L<=l&&r<=R){
		return number[rt];
	}
	if(L>r||R<l) return 0;
	int mid=(l+r)/2;
	pushdown(rt);
	return query(rt*2,L,R,l,mid)+query(rt*2+1,L,R,mid+1,r);
}
void build(int l, int r, int rt) { //一开始0的数量是满的 
  number[rt] = r - l + 1;
  if(l == r) return;
  int mid = (l + r) / 2;
  build(l, mid, 2 * rt);
  build(mid + 1, r, 2 * rt + 1);
}


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=0;i<=4*n;i++)
	   bz[i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].val);
	}
	sort(a+1,a+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int num=query(1,a[i].l,a[i].r,1,n);//0的数量
		num=a[i].r-a[i].l+1-num;//1的数量 
		if(num<a[i].val){
		int l=a[i].l,r=a[i].r;
		int pos=-1;
		while(l<=r){   //二分找0的个数差的1刚好对上的位置 
			int mid=(l+r)/2;
			if(query(1,mid,a[i].r,1,n)>=a[i].val-num){
				pos=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ins(1,pos,a[i].r,1,n);
		ans+=a[i].val-num;
	    }
	}
	printf("%d\n",ans);
	return 0;
}
