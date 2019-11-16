#include<cstdio>
#include<queue>
using namespace std;
int n,m,s;
int v[105][105][105];//s//n//m
struct pp
{
	int n;
	int m;
	int s;
	int ans;
};
void bfs()
{
	int i,j,k,a;
	for(i=0;i<=s;i++)
	  for(j=0;j<=n;j++)
	    for(k=0;k<=m;k++)
	    v[i][j][k]=0;
	queue<pp>d;
	d=queue<pp>();
	pp cur,next;
	cur.ans=0;
	cur.m=0;
	cur.n=0;
	cur.s=s;
	d.push(cur);
	v[s][0][0]=1;
	while(!d.empty())
	{
		cur=d.front();
		d.pop();
		if((cur.n==s/2&&cur.s==s/2)||(cur.n==s/2&&cur.m==s/2)||(cur.m==s/2&&cur.s==s/2))
		{
			printf("%d\n",cur.ans);
			return;
		}
		if(cur.s&&cur.m!=m)   //s->m
		{
			a=m-cur.m;
			if(cur.s>=a)
			{
				next.m=m;
				next.s=cur.s-a;
			}
			else
			{
				next.m=cur.m+cur.s;
				next.s=0;
			}
			next.n=cur.n;
			next.ans=cur.ans+1;
			if(v[next.s][next.n][next.m]==0)
			{
			  v[next.s][next.n][next.m]=1;
			  d.push(next);
		    }
		}
		if(cur.s&&cur.n!=n)   //s->n
		{
			a=n-cur.n;
			if(cur.s>=a)
			{
				next.n=n;
				next.s=cur.s-a;
			}
			else
			{
				next.n=cur.n+cur.s;
				next.s=0;
			}
			next.m=cur.m;
			next.ans=cur.ans+1;
			if(v[next.s][next.n][next.m]==0)
			{
			  v[next.s][next.n][next.m]=1;
			  d.push(next);
		    }
		}
		if(cur.m&&cur.n!=n)    //m->n
		{
			a=n-cur.n;
			if(cur.m>=a)
			{
				next.n=n;
				next.m=cur.m-a;
			}
			else
			{
				next.n=cur.n+cur.m;
				next.m=0;
			}
			next.s=cur.s;
			next.ans=cur.ans+1;
			if(v[next.s][next.n][next.m]==0)
			{
			  v[next.s][next.n][next.m]=1;
			  d.push(next);
		    }
		}
		if(cur.m&&cur.s!=s)    //m->s
		{
			a=s-cur.s;
			if(cur.m>=a)
			{
				next.s=s;
				next.m=cur.m-a;
			}
			else
			{
				next.s=cur.s+cur.m;
				next.m=0;
			}
			next.n=cur.n;
			next.ans=cur.ans+1;
			if(v[next.s][next.n][next.m]==0)
			{
			  v[next.s][next.n][next.m]=1;
			  d.push(next);
		    }
		}
		if(cur.n&&cur.s!=s)     //n->s
		{
			a=s-cur.s;
			if(cur.n>=a)
			{
				next.s=s;
				next.n=cur.n-a;
			}
			else
			{
				next.s=cur.s+cur.n;
				next.n=0;
			}
			next.m=cur.m;
			next.ans=cur.ans+1;
			if(v[next.s][next.n][next.m]==0)
			{
			  v[next.s][next.n][next.m]=1;
			  d.push(next);
		    }
		}
		if(cur.n&&cur.m!=m)     //n->m
		{
			a=m-cur.m;
			if(cur.n>=a)
			{
				next.m=m;
				next.n=cur.n-a;
			}
			else
			{
				next.m=cur.n+cur.m;
				next.n=0;
			}
			next.s=cur.s;
			next.ans=cur.ans+1;
			if(v[next.s][next.n][next.m]==0)
			{
			  v[next.s][next.n][next.m]=1;
			  d.push(next);
		    }
		}
	}
	printf("NO\n");
	return;
	
}




int main()
{
	while(~scanf("%d%d%d",&s,&n,&m)&&s&&n&&m)
	{
		if(s%2!=0) printf("NO\n");
		else if(n==m&&n+m==s) printf("1\n");
		else bfs();
	}
	return 0;
} 
