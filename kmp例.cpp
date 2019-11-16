#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int f[105];
string s1="AABBCC"; 
string s2="ABCAABBCCASD";

void make_f(){
	f[0]=0;
	int n=s1.size();
	int len=0;
	int i=1;
	while(i<n){
		if(s1[i]==s1[len]){
			len++;
			f[i]=len;
			i++;
		}
		else{
			if(len>0){
				len=f[len-1];
			}
			else{
				f[i]=len;
				i++;
			}
		}
	}
}

void move_f(){
	for(int i=s1.size()-1;i>0;i--)
	  f[i]=f[i-1];
	f[0]=-1;  
}

void kmp(){
	int n=s1.size();
	int m=s2.size();
	int i=0,j=0;
	while(i<m){
		if(j==n-1&&s1[j]==s2[i]){
			printf("%d ",i-j);
			j=f[j];
		}
		if(s1[j]==s2[i]){
			i++;j++;
		}
		else{
			j=f[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
}


int main(){
  make_f();	
  move_f();
  kmp(); 
} 

