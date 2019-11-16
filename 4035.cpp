/*
    dp求期望的题。
    题意：
    有n个房间，由n-1条隧道连通起来，实际上就形成了一棵树，
    从结点1出发，开始走，在每个结点i都有3种可能：
        1.被杀死，回到结点1处（概率为ki）
        2.找到出口，走出迷宫 （概率为ei）
        3.和该点相连有m条边，随机走一条
    求：走出迷宫所要走的边数的期望值。
    
    设 E[i]表示在结点i处，要走出迷宫所要走的边数的期望。E[1]即为所求。
    
    叶子结点：
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)*(E[father[i]] + 1);
         = ki*E[1] + (1-ki-ei)*E[father[i]] + (1-ki-ei);
    
    非叶子结点：（m为与结点相连的边数）
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)/m*( E[father[i]]+1 + ∑( E[child[i]]+1 ) );
         = ki*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei)/m*∑(E[child[i]]) + (1-ki-ei);
    
    设对每个结点：E[i] = Ai*E[1] + Bi*E[father[i]] + Ci;
    
    对于非叶子结点i，设j为i的孩子结点，则
    ∑(E[child[i]]) = ∑E[j]
                   = ∑(Aj*E[1] + Bj*E[father[j]] + Cj)
                   = ∑(Aj*E[1] + Bj*E[i] + Cj)
    带入上面的式子得
    (1 - (1-ki-ei)/m*∑Bj)*E[i] = (ki+(1-ki-ei)/m*∑Aj)*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei) + (1-ki-ei)/m*∑Cj;
    由此可得
    Ai =        (ki+(1-ki-ei)/m*∑Aj)   / (1 - (1-ki-ei)/m*∑Bj);
    Bi =        (1-ki-ei)/m            / (1 - (1-ki-ei)/m*∑Bj);
    Ci = ( (1-ki-ei)+(1-ki-ei)/m*∑Cj ) / (1 - (1-ki-ei)/m*∑Bj);
    
    对于叶子结点
    Ai = ki;
    Bi = 1 - ki - ei;
    Ci = 1 - ki - ei;
    
    从叶子结点开始，直到算出 A1,B1,C1;
    
    E[1] = A1*E[1] + B1*0 + C1;
    所以
    E[1] = C1 / (1 - A1);
    若 A1趋近于1则无解...
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


vector<int>v[10005];
double dp[10005];
double k[10005];
double e[10005];
double A[10005];
double B[10005];double C[10005];

bool dfs(int x,int fa){
	if(v[x].size()==0&&fa!=-1){ //叶子结点 
		A[x]=k[x];
		B[x]=1-k[x]-e[x];
		C[x]=1-k[x]-e[x];
		return true;
	}
	//非叶子结点 
	A[x]=k[x];
	B[x]=(1-k[x]-e[x])/v[x].size();
	C[x]=1-k[x]-e[x];
	double tmp=0;//走到儿子的几率 
	for(int j=0;j<v[x].size();j++){
		if(v[x][j]==fa) continue;
		if(!dfs(v[x][j],x)) return false; 
		A[x]+=A[v[x][j]]*B[x];
		C[x]+=C[v[x][j]]*B[x];
		tmp+=B[v[x][j]]*B[x];
	}
	if(fabs(tmp-1)<1e-10) return false;
	A[x]/=(1-tmp);
	B[x]/=(1-tmp);
	C[x]/=(1-tmp);
	return true;
}

int main(){
	int T,n;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case %d: ",t);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		  v[i].clear();
		for(int i=1;i<n;i++){
			int s,t;
			scanf("%d%d",&s,&t);
			v[s].push_back(t);
			v[t].push_back(s);
		}
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&k[i],&e[i]);
			k[i]/=100;
			e[i]/=100;
		}
		if(dfs(1,-1)&&fabs(1-A[1])>1e-10)
		  printf("%.6lf\n",C[1]/(1-A[1]));
		else 
		  printf("impossible\n");    
	}
	
	return 0;
} 
