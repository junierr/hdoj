#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int z[1000005];
char s1[1000005];
char s2[1000005];
char ss[1000005];

void getz(int len){
		for(int i=0;i<len;i++) z[i]=0;
		int l=0,r=0;
		for(int i=1;i<len;i++){
			if(i<=r)
			  z[i]=min(r-i+1,z[i-l]);
			while(i+z[i]<len&&s2[z[i]]==s2[i+z[i]]) z[i]++;
			if(i+z[i]-1>r) l=i,r=i+z[i]-1;  
		}
}


int main(){
	int T;
	char m[30];
	scanf("%d",&T);
	while(T--){
		scanf("%s",s1);
		scanf("%s",s2);
		for(int i=0;i<26;i++){
			m[s1[i]-'a']='a'+i;
		}
		int len=strlen(s2);
		for(int i=0;i<len;i++)
		  ss[i]=s2[i];
		int tlen=len;
		len=len/2;
		if(tlen%2==1) len++;
		for(int i=0;i<len;i++)
		  s2[i]=m[s2[i]-'a'];    
		getz(tlen);
		int maxx=0;
		for(int i=len;i<tlen;i++){
			if(z[i]+i>=tlen) //密文比原文长 
			  maxx=max(maxx,z[i]);
		}
		int slen=tlen-maxx;  //原串减去最大匹配串长度即为密文长度 
		ss[slen]='\0';
	    printf("%s",ss);
		for(int i=0;i<slen;i++)
		  ss[i]=m[ss[i]-'a'];
		  //printf("%c",m[ss[i]]);
		printf("%s",ss);  
		printf("\n");    
	}
	return 0;
}
