#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int map[1010][1010];
int a[1010][1010];

int lowbit(int x)
{
	return (x&(-x));
}
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}


void update(int i,int j,int x)
{
	int p,q;
	for(p=i;p<1005;p+=lowbit(p))
	  for(q=j;q<1005;q+=lowbit(q))
	    a[p][q]+=x;
}

int sum(int i,int j)
{
	int ret=0;
	int x,y;
	for(x=i;x>0;x-=lowbit(x))
	  for(y=j;y>0;y-=lowbit(y))
	    ret+=a[x][y];
	return ret;    
}
int main()
{
	int T,t,i,q,j,x1,x2,y1,y2,x11,x22,y11,y22,n1;
	char s[10];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		printf("Case %d:\n",t);
		memset(a,0,sizeof(a));
		for(i=1;i<1005;i++)
		  for(j=1;j<1005;j++)
		  {
		  	map[i][j]=1;
		  	update(i,j,1);
		  }
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%s",s);
			if(s[0]=='S')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++;y1++;x2++;y2++;
				x11=min(x1,x2);x22=max(x1,x2);
				y11=min(y1,y2);y22=max(y1,y2);
				printf("%d\n",sum(x22,y22)-sum(x11-1,y22)-sum(x22,y11-1)+sum(x11-1,y11-1));
			}
			else if(s[0]=='A')
			{
				scanf("%d%d%d",&x1,&y1,&n1);
				x1++;y1++;
				update(x1,y1,n1);
				map[x1][y1]+=n1;
			}
			else if(s[0]=='D')
			{
				scanf("%d%d%d",&x1,&y1,&n1);
				x1++;y1++;
				if(map[x1][y1]<n1) 
				{
				  n1=map[x1][y1];
			    }
			    map[x1][y1]-=n1;
			    update(x1,y1,-n1);
			}
			else if(s[0]=='M')
			{
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n1);
				x1++;y1++;x2++;y2++;
				if(map[x1][y1]<n1)
				{
					n1=map[x1][y1];
				}
				map[x1][y1]-=n1; 
				map[x2][y2]+=n1;
				update(x1,y1,-n1);
				update(x2,y2,n1);
			}
		}
	}
	return 0;
 } 
