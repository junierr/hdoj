#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int sg[1050],f[1050];

int g(int x){
	int mex[1010];
	memset(mex,0,sizeof(mex));
	if(sg[x]!=-1) return sg[x];
	for(int i=1;f[i]<=x;i++)
	  mex[sg[x-f[i]]]=1;
	for(int i=0;;i++)
	  if(!mex[i]) return sg[x]=i;  
}

int main(){
	int n,m,p;
	memset(sg,-1,sizeof(sg));
	f[0]=f[1]=1;
	for(int i=2;i<=16;i++)
	  f[i]=f[i-1]+f[i-2];
	for(int i=0;i<1001;i++)
	  g(i);
	while(~scanf("%d%d%d",&m,&n,&p)){
		if(!m&&!n&&!p) break;
		if((sg[m]^sg[n]^sg[p])==0)
		  printf("Nacci\n");
		else
		  printf("Fibo\n");  
	}    
	return 0;
} 
