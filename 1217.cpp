#include<cstdio>
#include<cstring>
using namespace std;
double map[35][35];
int n,m;

void dd()
{
    int i,j,k,flag;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    for(k=0;k<n;k++)
	    {
	    	if(map[i][j]<map[i][k]*map[k][j])
	    	  map[i][j]=map[i][k]*map[k][j];
		}
	flag=0;
	for(i=0;i<n;i++)
	{
		if(map[i][i]>1) 
		{
		  flag=1;
		  break;
	    }
	}	
	if(flag==1) printf("Yes\n");
	else printf("No\n");
	return;	
}

int main()
{
	int t=1,i,j,a,b;
	double x;
	char name[100][100];
	char c1[100],c2[100];
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		  {
		  	map[i][j]=0;
		  }
		for(i=0;i<n;i++)
		{
			scanf("%s",name[i]);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s%lf%s",c1,&x,c2);
			for(j=0;j<n;j++)
			{
				if(strcmp(name[j],c1)==0) a=j;
				if(strcmp(name[j],c2)==0) b=j;
			}
			map[a][b]=x;
		}
		printf("Case %d: ",t++);
		dd();
	}
	return 0;
} 
