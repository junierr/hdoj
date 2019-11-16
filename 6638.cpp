#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int N=2010;
const int M=8010;
struct pp{
	int x,y,z,x1,y1;
}a[N];

long long pre[M],suf[M],s[M],v[M];
int pos[N];

bool cmp1(pp x,pp y){
	if(x.x==y.x)
	  return x.y<y.y;
	return x.x<y.x;
}

bool cmp2(pp x,pp y){
	if(x.y==y.y)
	  return x.x<y.x;
	return x.y<y.y;
}

void build(int x,int a,int b){
  pre[x]=suf[x]=s[x]=v[x]=0;
  if(a==b){
    pos[a]=x;
    return;
  }
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
inline void change(int x,int p){
  x=pos[x];
  s[x]+=p;
  if(s[x]>0)pre[x]=suf[x]=v[x]=s[x];else pre[x]=suf[x]=v[x]=0;
  for(x>>=1;x;x>>=1){
    pre[x]=max(pre[x<<1],s[x<<1]+pre[x<<1|1]);
    suf[x]=max(suf[x<<1|1],s[x<<1|1]+suf[x<<1]);
    s[x]=s[x<<1]+s[x<<1|1];
    v[x]=max(max(v[x<<1],v[x<<1|1]),suf[x<<1]+pre[x<<1|1]);
  }
}

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a,a+n,cmp2);
		int now=0;
		int ii=0;
		long long ans=0;
		for(int i=0;i<n;i++){ //¶ÔyÀëÉ¢»¯ 
			if(a[i].y!=now){
				now=a[i].y;
				a[i].y1=++ii;
			}
			else{
				a[i].y1=ii;
			}
		} 
		sort(a,a+n,cmp1);//xÅÅÐò 
		int k;
		for(int i=0;i<n;i++){
			if(i==0||a[i].x!=a[i-1].x){
				build(1,1,ii);
     		 	for(int j=i;j<n;j=k){
        		for(k=j;k<n&&a[j].x==a[k].x;k++)change(a[k].y1,a[k].z);
        		if(ans<v[1])ans=v[1];
      			}
			}
		}
    	printf("%lld\n",ans);     		  
	}
	return 0;
}
