/*
找一个最大的p，使得a和b的1到p中任意子串的最小值下标相同
标记当前位置左边第一个小于他的下标+1
从左往右找完全相同的 
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
