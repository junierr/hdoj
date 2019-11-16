/*
dp[i][j]代表到第i位余数为j的子串个数 
*/

 

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long dp[maxn][305];
int main(){
    string st;
    cin>>st;
    int len=st.size();
    long long ans=0;
    for(int i=0;i<len;i++){
        dp[i+1][(st[i]-'0')]=1;
        for(int j=0;j<300;j++){
            dp[i+1][(j*10+(st[i]-'0'))%300]+=dp[i][j];
        }
        ans+=dp[i+1][0];
        printf("%d %lld\n",i,ans); 
    }  
    cout<<ans<<endl;
    return 0;
}
