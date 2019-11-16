#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

char s[2005];
char sta[30];

int main(){
	int T,f1,f2,f3;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		f1=0;f2=0;f3=0;//¸ÉÔï£¬³±Êª£¬ÓÐº¦ 
		scanf("%s",s);
		scanf("%s",sta);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			s[i]=sta[s[i]-'a'];
			if(s[i]=='d'){
				f1++;
			}
			else if(s[i]=='w'){
				f2++;
			}
			else if(s[i]=='h'){
				f3++;
			}
		}
		if(f3*4>=len){
			printf("Case #%d: Harmful\n",t);
		}
		else if(f3*10<=len){
			printf("Case #%d: Recyclable\n",t);
		}
		else if(f1>=f2*2){
			printf("Case #%d: Dry\n",t);
		}
		else{
			printf("Case #%d: Wet\n",t);
		}
	}
	return 0;
} 
