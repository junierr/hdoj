/*
��һ������p��ʹ��a��b��1��p�������Ӵ�����Сֵ�±���ͬ
��ǵ�ǰλ����ߵ�һ��С�������±�+1
������������ȫ��ͬ�� 
*/
#include<cstdio>
#include<cstring>
using namespace std;

int a[100005],b[100005];
int l1[100005],l2[100005];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
		  l1[i]=l2[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			l1[i]=i;
			while(l1[i]>0&&a[l1[i]-1]>=a[i])
			  l1[i]=l1[l1[i]-1];
		}  
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			l2[i]=i;
			while(l2[i-1]>0&&b[l2[i]-1]>=b[i])
			  l2[i]=l2[l2[i]-1];
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		  printf("%d ",l1[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
		  printf("%d ",l2[i]);
		printf("\n");
	
		for(int i=1;i<=n;i++){
			if(l1[i]!=l2[i])
			  break;
			ans=i;  
		}
		printf("%d\n",ans); 
	}
	return 0;
} 
