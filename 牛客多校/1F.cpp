#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long x1,y1,x2,y2,x3,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        
        long long s=abs(((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y1-x1*y3))*11);
        cout<<s<<endl;
    }
    return 0;
}

