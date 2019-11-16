#include<stdio.h>
int main()
{
	int m ,n,s,d;long a[100][100];int b[100][100];long max=0;
	while(~scanf("%d %d",&m,&n))
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%ld",&a[i][j]);
				if(a[i][j]<0)
				{
					a[i][j]=-a[i][j];
					b[i][j]=1;
				}
				if(max<a[i][j])
				{
					max=a[i][j];
					s=i;d=j;
				}
			}
		}
		if(b[s][d]==1) printf("%d %d %ld\n",s,d,-max);
		if(b[s][d]==0) printf("%d %d %ld\n",s,d,max);
		max=0;
		for(int k=1;k<=m;k++)
		for(int l=1;l<=n;l++)
		b[k][l]=0;
	}
	return 0;
 } 
