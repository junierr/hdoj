#include<stdio.h>
#include<string.h>
int shu(char a) 
{
	int dum;
	dum=int(a-'0');
	return dum;
}


int main()
{
	int n,j,a1,b1,t,k;
	char a[1000];
	char b[1000];
	int sum[1000];
	while(~scanf("%d",&n))
	{
		j=1;
		while(n--)
		{
			scanf("%s",a);
			a1=strlen(a);
			scanf("%s",b);
			b1=strlen(b);
			if(j!=1) printf("\n");
			if(a1>b1) k=a1;
			else k=b1;
			t=k;
			for(int i=0;i<=k;i++) sum[i]=0;
			for(k;a1>0&&b1>0;k--)
			{
				sum[k]+=shu(a[--a1])+shu(b[--b1]);
				if(sum[k]/10)
				{
					sum[k-1]++;
					sum[k]%=10;
				}
			}
			while(a1>0)
			{
				sum[k--]+=shu(a[--a1]);
				if(sum[k]/10)
				{
					sum[k-1]++;
					sum[k]%=10;
				}
			}
			while(b1>0)
			{
			   sum[k--]+=shu(b[--b1]);
				if(sum[k]/10)
				{
					sum[k-1]++;
					sum[k]%=10;
				}	
			}
	        printf("Case %d:\n",j++);
			printf("%s + %s = ",a,b);
			for(int x=0;x<=t;x++)
			{
			  if(x==0&&sum[x]==0) x++;
			  printf("%d",sum[x]);
			}
			printf("\n");	
		}
	}
	return 0;
 } 
