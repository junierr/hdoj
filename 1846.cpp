/*
(m+1)*r+s
��һ��ȡ��s��֮��ÿ������m+1�ı��������ɻ�ʤ 
*/


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;



int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n%(m+1)==0)printf("second\n");
		else printf("first\n");
		}  
	return 0;
}
