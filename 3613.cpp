#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[500005];
char ss[1000005];
int p[1000005];
int sum[500005];
int v[29];

int init(){
	int i,len=strlen(s);
	ss[0]='@';
    for(i=1;i<=2*len;i+=2){
    	ss[i]='#';
    	ss[i+1]=s[i/2];
	}
	ss[len*2+1]='#';
	ss[len*2+2]='\0';
	return 2*len+2;
}

void manacher(int len){ //回文串 
	int pos=0,mx=0;
	for(int i=1;i<=len;i++){
		if(i<mx) p[i]=min(p[2*pos-i],mx-i);
		else p[i]=1;
		while(ss[i+p[i]]==ss[i-p[i]]) p[i]++;
		if(mx<p[i]+i){
			mx=p[i]+i;
			pos=i;
		} 
	}
}

void getsum(){  //价值 
    int len=strlen(ss);
	sum[0]=0;
	for(int i=1;i<len;i++){
		sum[i]=sum[i-1];
		if('a'<=ss[i]&&ss[i]<='z')
		  sum[i]+=v[ss[i]-'a'+1];
	} 
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=26;i++)
		  scanf("%d",&v[i]);
		scanf("%s",s);
		int len=init(); 
		manacher(len); 
		getsum();
		int ans=-100*500000;
		for(int i=3;i<len-2;i+=2){ //割的是#号 
		   	int a1=0,a2=0;
		   	int mid=(i+1)/2;//中点 
		   	if(mid+p[mid]-1==i)
		   	  a1=sum[i];
		   	mid=(len+i-1)/2;  
		   	if(mid+p[mid]==len)
			   a2=sum[len-1]-sum[i];  
			if(ans<a1+a2)
			  ans=a1+a2;   
		}
		printf("%d\n",ans);
		/*int tmp,mid,res=-100*500000;
        for(int i=3;i<len-2;i+=2){
          tmp=0; mid = (i+1)/2;
          if(mid+p[mid]-1==i) tmp+=sum[i];
          mid = (len-1+i)/2;
          if(mid+p[mid]==len) tmp+=sum[len-1]-sum[i];
          res=max(res,tmp);
    }
		printf("%d\n",res);*/
	}
	return 0;
} 
