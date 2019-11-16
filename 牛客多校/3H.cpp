/*
สýังฬโ 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

struct pp{
	int x,y;
}a[1005];

bool cmp(pp x,pp y){
	if(x.x==y.x)
	  return x.y<y.y;
	return x.x<y.x;  
}

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		sort(a+1,a+n+1,cmp);
		int x1=a[n/2].x,y1=a[n/2].y;
		printf("%d %d %d %d\n",x1-1,y1+999000001,x1+1,y1-999000000);
	}
	return 0;
} 
