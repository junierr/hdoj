#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string> 
#include<cmath>
#include<iostream>
using namespace std;

char s[150];
char ss[150];

char tos(char x1,char x2,char x3,char x4){
	int x=(x4-'0')+(x3-'0')*2+(x2-'0')*4+(x1-'0')*8;
	if(x==0) return '0';
	else if(x==1) return '1';
	else if(x==2) return '2';
	else if(x==3) return '3';
	else if(x==4) return '4';
	else if(x==5) return '5';
	else if(x==6) return '6';
	else if(x==7) return '7';
	else if(x==8) return '8';
	else if(x==9) return '9';
	else if(x==10) return 'a';
	else if(x==11) return 'b';
	else if(x==12) return 'c';
	else if(x==13) return 'd';
	else if(x==14) return 'e';
	else if(x==15) return 'f';
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%s",s);
		int cnt=0;
		for(int i=0;i<128;i+=4){ //转16进制 
			ss[cnt++]=tos(s[i],s[i+1],s[i+2],s[i+3]);
		}
		int now=0;
		int maxn=-1;
		int p1=-1,p2=-1;
		for(int i=0;i<32;i+=4){//找最长0 
			if(ss[i]=='0'&&ss[i+1]=='0'&&ss[i+2]=='0'&&ss[i+3]=='0'){
				if(now==0) p1=i;
				now++;
				if(maxn<=now){
					if(maxn==now&&(i+4==32)&&(p2!=0)) continue; 
					maxn=now;
					p2=p1;
				}
			}
			else {
				now=0;
			}
		}
		printf("Case #%d: ",t);
		for(int i=0;i<32;i+=4){
			if(i==p2&&maxn>1){
				if(p2==0)printf("::");
				else printf(":");
				i+=(maxn*4);
				i-=4;
				continue;
			}
			else{
				int j=i;
				while(ss[j]=='0'&&j<i+4){
					j++;
				}
				if(j==i+4&&i!=28){
					printf("0:");
				}
				else if(j==i+4&&i==28){
					printf("0");
				}
				else if(j<i+4&&i!=28){
					for(int k=j;k<i+4;k++){
						printf("%c",ss[k]);
					}
					printf(":");
				}
				else if(j<i+4&&i==28){
					for(int k=j;k<i+4;k++){
						printf("%c",ss[k]);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
