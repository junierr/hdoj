#include<stdio.h>
int main()
{
	int n,m;
	char a[100][100];
	while(~scanf("%d%d",&n,&m))
	{
		for(int k=0;k<=m+1;k++)
		  for(int y=0;y<=n+1;y++)
		    a[k][y]=' ';
		a[0][0]='+';
		a[m+1][0]='+';
		a[0][n+1]='+';
		a[m+1][n+1]='+';
		for(int i=1;i<=n;i++)
		 {
		    a[0][i]='-';
	        a[m+1][i]='-';
		 }
		for(int j=1;j<=m;j++)
		  {
		  	a[j][0]='|';
		  	a[j][n+1]='|';
		  }
		  for(int x=0;x<=m+1;x++)
		  {
		  	for(int o=0;o<=n+1;o++)
		  	  printf("%c",a[x][o]);
		  	printf("\n");  
		  }
		  printf("\n");
	}
	return 0;
}
