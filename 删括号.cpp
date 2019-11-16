/*
dp[i][j][k]表示a到前i个，b到前j个，还可以再删除k个右括号的情况是否有可能
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int dp[150][105][150]={0};
char s1[150],s2[150]; 

int main(){
    scanf("%s%s",s1+1,s2+1);
	int lens1=strlen(s1+1);
	int lens2=strlen(s2+1);
	dp[0][0][0]=1;
	for(int i=0;i<lens1;i++)
	  for(int j=0;j<=lens2;j++)
	    for(int k=0;k<=lens1;k++){
	    	if(dp[i][j][k]){
	    		if(k==0&&s1[i+1]==s2[j+1])//当k>0时不能不删 
	    		  dp[i+1][j+1][k]=1;
	    		if(s1[i+1]=='(')
				  dp[i+1][j][k+1]=1;
				else if(k) dp[i+1][j][k-1]=1;    
			}
		}
	puts(dp[lens1][lens2][0]?"Possible":"Impossible");
	return 0;
} 
