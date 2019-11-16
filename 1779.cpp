#include<bits/stdc++.h>
using namespace std;

struct magic
{
	char name[100];
	long long mp;
	char target[10];
	long long damage;
};
	long long ans=(long long)1<<50;
	long long i,j,k,n,m,rest,maxi=0,t=0,flag=0;
	long long hp[105];
	magic g[105];
	long long f1[100005],f2[100005];
int main()
{
	memset(f1,-1,sizeof(f1));
	memset(f2,-1,sizeof(f2));
	f1[0]=0;f2[0]=0;
	cin>>n;
	for(i=0;i<n;i++)
	  {
	  	cin>>hp[i];
	  	if(hp[i]>maxi) maxi=hp[i];
	  }
	cin>>m;
	for(i=0;i<m;i++)
	  {
	  	cin>>g[i].name>>g[i].mp>>g[i].target>>g[i].damage;
	  	if(g[i].damage&&g[i].mp==0)
	  	{
	  		t=1;
		}
		if(g[i].damage==0) 
		{
			i--;m--;
		    continue;
		}
		if(g[i].damage>maxi) g[i].damage=maxi;
	  }
	  if(t==1) 
	  {
	      cout<<"0"<<endl;
	      return 0;
	  }
	  
	  
	  for(i=0;i<m;i++)
	  {
	  	 if(g[i].target[0]=='A') //qun
	  	 {
	  	 	for(j=1;j<=maxi;j++)
	  	 	{
	  	 		if(j>=g[i].damage&&f1[j-g[i].damage]!=-1)
				{
	  	 			if(f1[j]==-1) f1[j]=f1[j-g[i].damage]+g[i].mp;
					else f1[j]=min(f1[j],f1[j-g[i].damage]+g[i].mp);
				}
				else
				{
					if(f1[j]==-1) f1[j]=g[i].mp;
					else f1[j]=min(f1[j],g[i].mp); 
				}
			}
		 }
		 else  //dan 
		 {
		 	for(j=1;j<=maxi;j++)
		 	{

				 flag=1;
				 if(j>=g[i].damage&&f2[j-g[i].damage]!=-1)
				 {
		 			if(f2[j]==-1) f2[j]=f2[j-g[i].damage]+g[i].mp;
					else f2[j]=min(f2[j],f2[j-g[i].damage]+g[i].mp);
				 }
				 else
				 {
				 	if(f2[j]==-1) f2[j]=g[i].mp;
				 	else f2[j]=min(f2[j],g[i].mp);
				 }
			 }
		 }
	   }
       if(flag==0)
       {
       	  cout<<f1[maxi]<<endl;
       	  return 0;
	   }
	   

	   for(i=0;i<=maxi;i++)
	   {
		  if(f1[i]==-1) continue;
		  rest=f1[i];
	   	  for(j=0;j<n;j++)
	   	  {
	   	  	 if(hp[j]-i>0&&f2[hp[j]-i]!=-1)
	   	  	   rest+=f2[hp[j]-i];  
		  }
		  if(ans>rest) ans=rest;
	   }
	cout<<ans<<endl;
	return 0;  
} 
