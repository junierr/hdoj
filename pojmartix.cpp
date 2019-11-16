#include<cstdio>
#include<cstring>
using namespace std;
int c[1005][1005];
int n;

int lowbit(int a)
{
	return (a&(-a));
}

void update(int i,int j,int a)
{
	int p,q;
	for(p=i;p<=n;p+=lowbit(p))
	  for(q=j;q<=n;q+=lowbit(q))
	    c[p][q]+=a;
	return;	 
}

int sum(int i,int j)
{
	int p,q,ret=0;
	for(p=i;p>0;p-=lowbit(p))
	  for(q=j;q>0;q-=lowbit(q))
	    ret+=c[p][q];
	return ret;    
}
int main() 
{
	int x,t,i,x1,x2,y1,y2;
	char s[10];
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d%d",&n,&t);
		memset(c,0,sizeof(c));
		for(i=0;i<t;i++)
		{
			scanf("%s",s);
			if(s[0]=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				update(x1,y1,1);
				update(x2+1,y1,1);
				update(x1,y2+1,1);
				update(x2+1,y2+1,1);
			}
			else if(s[0]=='Q')
			{
				scanf("%d%d",&x1,&y1);
				int m=sum(x1,y1);
				if(m%2==0) printf("0\n");
				else printf("1\n");
			}
		}
		if(x!=0) printf("\n");
	}
	return 0;
}
