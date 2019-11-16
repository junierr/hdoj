#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool judge(int y){
	if(y%4==0&&y%100!=0||y%400==0)
	  return 1;
	return 0;  
}

int week(int y,int m,int d){
	if(m==1||m==2){
		m+=12;
		y--;
	}
	return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;
}


int main(){
	int T;
	scanf("%d",&T);
	int y,m,d;
	while(T--){
		scanf("%d-%d-%d",&y,&m,&d);
	    int w=week(y,m,d);
	    for(int i=y+1;;i++){
	    	if(judge(y)&&m==2&&d==29&&!judge(i)) continue;
	    	if(week(i,m,d)==w){
	    		printf("%d\n",i);
	    		break;
			}
		}
	}
	return 0;
}
