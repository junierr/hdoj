#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct pp{
	double x,y,t;
}a[1005];

bool cmp(pp x,pp y){
	return x.t>y.t;
}

int main(){
	int m,n;
	while(~scanf("%d%d",&m,&n)){
		if(m==-1&&n==-1) break;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&a[i].x,&a[i].y);
			a[i].t=a[i].x/a[i].y;
		}
		sort(a+1,a+1+n,cmp);
		double ans=0;
		for(int i=1;i<=n;i++){
			if(m>=a[i].y){
				m-=a[i].y;
				ans+=a[i].x;
			}
			else {
				ans+=a[i].t*m;
				break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
