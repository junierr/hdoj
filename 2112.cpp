#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
using namespace std;
map<string,int>d;
int mapp[160][160];
int k;
void dd(int start,int end)
{
	int f[160];
	int v[160];
	int min,next,i,j;
	for(i=0;i<k;i++)
	{
		f[i]=mapp[start][i];
        v[i]=0;	
	}
	f[start]=1;
	for(i=0;i<k;i++)
	{
		min=99999;
		for(j=0;j<k;j++)
		{
			if(v[j]==0&&min>f[j])
			{
				min=f[j];
				next=j;
			}
		}
		v[next]=1;
		for(j=0;j<k;j++)
		{
			if(v[j]==0&&f[j]>f[next]+mapp[next][j])
			  f[j]=f[next]+mapp[next][j]; 
		}
	}
	if(f[end]==99999) printf("-1\n");
	else printf("%d\n",f[end]);
	return; 
}
int main()
{
	int n,time,i,j;
	string c1,c2,start,end;
	while(cin>>n&&n!=-1)
	{
		for(i=0;i<=155;i++)
		  for(j=0;j<=155;j++)
		  {
		  	if(i==j) mapp[i][j]=0;
		  	else mapp[i][j]=99999;
		  }
		d.clear();
		cin>>start>>end;
		k=0;
		d[start]=k++;
		d[end]=k++;
		for(i=0;i<n;i++)
		{
			cin>>c1>>c2>>time;
			if(d.find(c1)==d.end()) d[c1]=k++;
			if(d.find(c2)==d.end()) d[c2]=k++;
			if(time<mapp[d[c1]][d[c2]]||time<mapp[d[c2]][d[c1]])
			  mapp[d[c1]][d[c2]]=mapp[d[c2]][d[c1]]=time;
		}
		if(start==end) printf("0\n");
		else dd(d[start],d[end]);
	}
	return 0;
}
