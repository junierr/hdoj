#include<bits/stdc++.h>
using namespace std;
int main()
{
	double v,d,t,sum,time;
	while(~scanf("%lf%lf",&v,&d))
	{
		sum=0;t=d;time=2;
		while(v>d)
		{
			sum+=time;
			time++;
			v-=d;
			d+=t;
		}
		if(v/t!=(int)(v/t)) v=(int)(v/t)+1;
		else v=v/t;
		sum+=v;
		printf("%d\n",(int)sum);
	}
	return 0;
}
