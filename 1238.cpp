#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

struct pp{
	char s[105];
}num[1005];

bool cmp(pp x,pp y){
  return strlen(x.s)<strlen(y.s);
}

int main(){
	int T,flag,i,j,k,l,len,ans,n,len1;
	char b[105];
	char p[105],q[105];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",num[i].s);
		}
		sort(num,num+n,cmp);
		strcpy(b,num[0].s);
		len=strlen(b);ans=0;
		for(i=0;i<len;i++){
			for(j=i;j<len;j++){
				int lenn=0;
				for(k=i,l=j;k<=j,l>=i;k++,l--){
					p[lenn]=b[k];
					q[lenn++]=b[l];
				}
				p[lenn]='\0';
				q[lenn]='\0';
				len1=strlen(p);flag=1;
				for(k=0;k<n;k++){
					if(strstr(num[k].s,p)==0&&strstr(num[k].s,q)==0){
						flag=0;
						break;
					}
				}
				if(flag&&len1>ans){
					ans=len1;
				}
			}
		}
		printf("%d\n",ans); 
	}
	return 0;
}
