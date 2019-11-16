#include<bits/stdc++.h>
using namespace std;
struct xy
{
    int x;
    int y;
}d[1000];
int g(int a,int b,int c)
{
    int t;
    t=(d[b].x-d[a].x)*(d[c].y-d[b].y)-(d[c].x-d[b].x)*(d[b].y-d[a].y);
    return t;
}
int main()
{
    int i,t,n;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&d[i].x,&d[i].y);
        }
        for(i=0;i<n;i++)
        {
            t=g(i%n,(i+1)%n,(i+2)%n);
            if(t<0)break;
        }
            if(t>=0)
                printf("convex\n");
            else
                printf("concave\n");
    }
    return 0;
}

