#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int v[1000];
struct pp
{
	char s[105];
};
queue<pp>d;
pp a[105];
int t;

void bfs()
{
	int len,i;
	pp cur,next;
	while(!d.empty())
	{
	  cur=d.front();
	  d.pop();
      len=strlen(cur.s);
      if(cur.s[len-1]=='m')
      {
      	  printf("Yes.\n");
      	  return;
	  }
	  for(i=0;i<t;i++)
	  {
	  	if(strcmp(cur.s,a[i].s)==0)
	  	{
	  		v[i]=1;
	  		break;
		}
	  }
	  for(i=0;i<t;i++)
	  {
	  	if(v[i]==0)
	  	{
	  		if(cur.s[len-1]==a[i].s[0])
	  		{
	  			v[i]=1;
	  			d.push(a[i]);
			}
		}
	  }
	}
	printf("No.\n");
	return;
}
int main()
{
	int len;
	t=0;
	d=queue<pp>();
	while(~scanf("%s",a[t].s)) 
	{
	  if(t==0) memset(v,0,sizeof(v));
	  if(a[t].s[0]=='0')
	  {
	  	bfs();
	  	t=0;
	  	d=queue<pp>();
	  	continue;
	  }
	  len=strlen(a[t].s);
	  if(a[t].s[0]==a[t].s[len-1]) continue;
	  if(a[t].s[0]=='b')
	  {
	  	d.push(a[t]);
	  	v[t]=1;
	  }
	  t++;
    }
	return 0;
} 
