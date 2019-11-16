#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int ranka[155][155],rankb[155][155];
int wife[155][155],husband[155];
int h[155],v[155],renshu[155];
int n,m,r,flag;

struct mm
{
	int id,ri,mi,k;
	int like[200];
}b[155],g[155];

bool cmp1(mm a, mm b)
{
	if((a.ri==r&&b.ri==r)||(a.ri!=r&&b.ri!=r))
	  return a.mi>b.mi;
	else if(a.ri==r&&b.ri!=r)
	  return a.mi>b.mi*0.7;
	else if(a.ri!=r&&b.ri==r)
	  return a.mi*0.7>b.mi;    
}

bool cmp2(mm a, mm b)
{
	return a.id<b.id;
}


void paixu()
{
	int i,j;
	memset(ranka,0,sizeof(ranka));
	memset(rankb,0,sizeof(rankb));
	memset(h,0,sizeof(h));
	for(i=1;i<=n;i++)
	  for(j=1;j<=b[i].k;j++)
	    ranka[i][j]=b[i].like[j];
	for(i=1;i<=m;i++)
	{
		r=g[i].ri;
		sort(b+1,b+n+1,cmp1);
		for(j=1;j<=n;j++)
		  rankb[i][b[j].id]=j;
		h[i]=1;  	
	}
	sort(b+1,b+n+1,cmp2);	 
}

void pp()
{
	int i,j;
	memset(wife,0,sizeof(wife));
	memset(husband,0,sizeof(husband));
	memset(v,0,sizeof(v));
	memset(renshu,0,sizeof(renshu));  
	flag=1;
	while(flag)
	{
		flag=0;
		for(i=1;i<=n;i++)
		{
			if(v[i]==0&&husband[i]==0)
			{
				flag=1;
				if(h[i]>b[i].k)
			    {
				  v[i]=1;
				  continue;
			    }
			    int girl=ranka[i][h[i]];
			    if(renshu[girl]<g[girl].mi)
			    {
			    	renshu[girl]++;
			    	wife[girl][renshu[girl]]=i;
			    	h[i]++;
			    	husband[i]=girl;
				}
				else
				{
					int minn=rankb[girl][i];
					int f=0;
					int num;
					for(j=1;j<=renshu[girl];j++) //找出最laji的进行替换 
					{
						if(rankb[girl][wife[girl][j]]>minn)
						{
							f=1;
							minn=rankb[girl][wife[girl][j]];
							num=j;
						}
					}
					if(f==1)
					{
						husband[wife[girl][num]]=0;
						husband[i]=girl;
					    h[i]++;
					    wife[girl][num]=i;
					}
					else h[i]++;
				}
			}	
		}
	}
	return;
}


int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(b,0,sizeof(b));
		memset(g,0,sizeof(g)); 
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&b[i].ri,&b[i].mi,&b[i].k);
			b[i].id=i;
			for(j=1;j<=b[i].k;j++)
			{
				scanf("%d",&b[i].like[j]);
			}
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&g[i].ri,&g[i].mi);
		}
		paixu();
		pp();
		for(i=1;i<=n;i++)
		  if(v[i])
		    printf("not accepted\n");
		  else 
		    printf("%d\n",husband[i]);
		if(T) printf("\n");	  
	}
	return 0;
 } 
