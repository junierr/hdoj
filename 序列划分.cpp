/*
��ĿҪʹ���ֺ��������С��������f(x)<=m,ʹ��m��С
���ֿ��ܵ�m���ж�m�Ƿ�������ҵ���Сm����µ����f(x)���� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	long long n,m;
	long long a[100005];
	while(T--){
		scanf("%lld%lld",&n,&m);
		long long maxx=0,sum=0;
		for(long long i=0;i<n;i++){
		  scanf("%lld",&a[i]);
	      maxx=max(maxx,a[i]);
	      sum+=a[i];
		}
		long long l=maxx,r=sum;
		long long ans=INF;
		while(l<=r){
			long long mid=(l+r)/2;
			long long temp=0;
			long long used=0;
			long long num=1;
			for(long long i=0;i<n;i++){
				if(temp+a[i]<=mid){
					temp+=a[i];
				}
				else {
					used=max(used,temp);
					temp=a[i];
					num++;
				}
				used=max(used,temp);
			}
			if(num<=m){
				ans=min(ans,used);
				r=mid-1;
			}
			else 
			  l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
