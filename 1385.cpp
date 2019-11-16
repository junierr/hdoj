#include<bits/stdc++.h>
using namespace std;
int mapp[205][205];
int tax[205];
int path[205][205];
int n;
void dd()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    path[i][j]=j;
	for(k=1;k<=n;k++)
	  for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
		{
			int x=mapp[i][k]+mapp[k][j]+tax[k];
			if(x<mapp[i][j])
			{
				mapp[i][j]=x;
				path[i][j]=path[i][k];
			}
			else if(x==mapp[i][j]&&path[i][j]>path[i][k])
			  path[i][j]=path[i][k];
		}    
}


int main()
{
	int i,j,k,s,t;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	scanf("%d",&mapp[i][j]);
		  	if(mapp[i][j]==-1) mapp[i][j]=999999;
		  }
		for(i=1;i<=n;i++)
		  scanf("%d",&tax[i]);
		dd();
		while(~scanf("%d%d",&s,&t)&&s!=-1&&t!=-1)
		{
			printf("From %d to %d :\n",s,t);
            printf("Path: %d",s);
            k=s;
            while(k!=t)
            {
            	printf("-->%d",path[k][t]);
            	k=path[k][t];
			}
			printf("\nTotal cost : %d\n\n",mapp[s][t]);
		}  
	}
	return 0;
 } 
