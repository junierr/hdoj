#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v[10];

bool cmp(vector<int > a,vector<int > b){
	for(int i=1;i<a.size();i++)
	  if(a[i]-a[i-1]!=b[i]-b[i-1])
	    return a[i]-a[i-1]<b[i]-b[i-1];	    
}

int main(){
	int T;
	scanf("%d",&T);
	vector<int > tmp;
	for(int i=1;i<=9;i++){
			tmp.clear();
			for(int j=1;j<=i;j++){
				tmp.push_back(j);
			}
			if(i<=8) 
			  {
			    do v[i].push_back(tmp);
			    while(next_permutation(tmp.begin(),tmp.end()));
			  }
			else{
				do v[i].push_back(tmp);
			    while(next_permutation(tmp.begin()+1,tmp.end()));
			}  
			sort(v[i].begin(),v[i].end(),cmp);  
		}

	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		if(n<=8){
			int len=v[n][k-1].size();
			for(int i=0;i<len-1;i++)
			  printf("%d ",v[n][k-1][i]);
			printf("%d\n",v[n][k-1][len-1]);
			continue; 
		}else{
			printf("%d",n);
			for(int i=1;i<=n-9;i++)
			  printf(" %d",i);
			for(int i=1;i<=8;i++){
				printf(" %d",v[9][k-1][i]+n-10);
			}
			printf("\n");  
		}
	}
	return 0;
} 
