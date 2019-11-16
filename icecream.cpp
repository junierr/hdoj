/*
对于一组数据来说,最优情况肯定是前x的作为底层，然后一点一点堆上去
所以我们二分可能的x，用上述方法判断x是否可行，使x最大即可 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct pp{
	long long val;
	long long c;
	pp(long long v,long long p):val(v),c(p){}
};
long long n,k;

long long a[100005];

bool judge(long long x){
	queue<pp>d;
	d=queue<pp>();
	long long num=0;
	for(long long i=0;i<x;i++){
		d.push(pp(a[i],1));
	}
	for(long long i=x;i<n;i++){
		if(d.empty())
		  break;
		while(d.front().c==k){
			d.pop();
			num++;
		}
        pp b=d.front();
        if(b.val*2>a[i]) continue;
        d.pop();
        d.push(pp(a[i],b.c+1));
	}
	while(!d.empty()){
		if(d.front().c==k)
		  num++;
		d.pop();  
	}
	return x==num;
}



int main(){
	long long T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(long long i=0;i<n;i++)
		  scanf("%lld",&a[i]);
		sort(a,a+n);
		long long l=0,r=n/k;
		long long ans=0;
		while(l<=r){
			long long mid=(l+r)/2;
			if(judge(mid)){
				ans=mid;
				l=mid+1;
			}
			else
			  r=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
