/*
�����ʱ����Ԥ�����һ��һ��һ��ans
Ȼ���գ�aiΪ������ai��С��bi�͵����������aiΪ������ai��bi�෴������ai����bi�͵���������� 
ÿ��ȡ��󼴿� 

(���㷨)
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

long long a[3000005],b[3000005];

int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
	  scanf("%lld",&b[i]);
      ans=max(ans,a[i]*b[i]);
	}
	long long s=0,minx=inf;
    for(int i=1;i<=n;i++){//a[i]+
      if(s+b[i]>=0){
          s+=b[i];
          minx=min(minx,a[i]);
      }
      else{
        s=0;
        minx=inf;  
      }
      ans=max(ans,minx*s);  
    }
    long long maxn=-inf;
    s=0;
    for(int i=1;i<=n;i++){
    a[i]=-a[i];b[i]=-b[i];
    }
    for(int i=1;i<=n;i++){//a[i]-
      if(s+b[i]>=0){
          s+=b[i];
          maxn=max(maxn,a[i]);
      }
      else{
        s=0;
        maxn=-inf;  
      }
      ans=max(ans,maxn*s); 
    }
    printf("%lld\n",ans);
    return 0;
} 
