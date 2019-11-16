/*
每一次对i来说，把左边比i大的移到右边，把右边比i小的移到左边，相对于左边那些大于i的数来说，
仍然在i的左边，所以找前i个有几个比i大的 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((x&(-x))) 
using namespace std;

struct pp{
	int val,num;
}a[100005];
const int L=100002;
int n,ans,sum[100005];
bool cmp(pp a,pp b){
	return a.val<b.val||(a.val==b.val&&a.num<b.num);
}



void update(int x){
	for(int i=x;i<=L;i+=lowbit(i))
	  sum[i]++;
}

int ask(int x) {
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	  res+=sum[i];
	return res;  
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<L;i++)
	  sum[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	ans=1;
	for(int i=1;i<=n;i++){
		update(a[i].num);
		ans=max(ans,i-ask(i));
	}
	printf("%d\n",ans);
	return 0;
}
