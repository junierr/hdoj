#include <stdio.h>
#include <math.h>
#include <algorithm>
#include<iostream>
using namespace std;

double x[10],y[10],ans,lx,rx,ly,ry;
int i;

void change(double &xx,double &yy)
{
double t;
 t=xx; xx=yy; yy=t;
}

int main(){
    while(scanf("%lf%lf",&x[1],&y[1])!=EOF)
	{
      for(i=2;i<=4;i++)
	  {
        scanf("%lf%lf",&x[i],&y[i]);
      }
       if(x[1]>x[2]){change(x[1],x[2]);}
       if(x[3]>x[4]){change(x[4],x[3]);}
       if(y[1]>y[2]){change(y[1],y[2]);}
       if(y[3]>y[4]){change(y[4],y[3]);} 

       lx=max(x[1],x[3]); rx=min(x[2],x[4]); 
       ly=max(y[1],y[3]); ry=min(y[2],y[4]); 
       if(lx<=rx&&ly<=ry)
	   {                   
        ans=1.0*fabs(rx-lx)*fabs(ry-ly);   
        printf("%.2lf\n",ans);
       }
       else{printf("0.00\n"); continue;} 

    }
    return 0;
}
