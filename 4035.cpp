/*
    dp���������⡣
    ���⣺
    ��n�����䣬��n-1�������ͨ������ʵ���Ͼ��γ���һ������
    �ӽ��1��������ʼ�ߣ���ÿ�����i����3�ֿ��ܣ�
        1.��ɱ�����ص����1��������Ϊki��
        2.�ҵ����ڣ��߳��Թ� ������Ϊei��
        3.�͸õ�������m���ߣ������һ��
    ���߳��Թ���Ҫ�ߵı���������ֵ��
    
    �� E[i]��ʾ�ڽ��i����Ҫ�߳��Թ���Ҫ�ߵı�����������E[1]��Ϊ����
    
    Ҷ�ӽ�㣺
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)*(E[father[i]] + 1);
         = ki*E[1] + (1-ki-ei)*E[father[i]] + (1-ki-ei);
    
    ��Ҷ�ӽ�㣺��mΪ���������ı�����
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)/m*( E[father[i]]+1 + ��( E[child[i]]+1 ) );
         = ki*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei)/m*��(E[child[i]]) + (1-ki-ei);
    
    ���ÿ����㣺E[i] = Ai*E[1] + Bi*E[father[i]] + Ci;
    
    ���ڷ�Ҷ�ӽ��i����jΪi�ĺ��ӽ�㣬��
    ��(E[child[i]]) = ��E[j]
                   = ��(Aj*E[1] + Bj*E[father[j]] + Cj)
                   = ��(Aj*E[1] + Bj*E[i] + Cj)
    ���������ʽ�ӵ�
    (1 - (1-ki-ei)/m*��Bj)*E[i] = (ki+(1-ki-ei)/m*��Aj)*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei) + (1-ki-ei)/m*��Cj;
    �ɴ˿ɵ�
    Ai =        (ki+(1-ki-ei)/m*��Aj)   / (1 - (1-ki-ei)/m*��Bj);
    Bi =        (1-ki-ei)/m            / (1 - (1-ki-ei)/m*��Bj);
    Ci = ( (1-ki-ei)+(1-ki-ei)/m*��Cj ) / (1 - (1-ki-ei)/m*��Bj);
    
    ����Ҷ�ӽ��
    Ai = ki;
    Bi = 1 - ki - ei;
    Ci = 1 - ki - ei;
    
    ��Ҷ�ӽ�㿪ʼ��ֱ����� A1,B1,C1;
    
    E[1] = A1*E[1] + B1*0 + C1;
    ����
    E[1] = C1 / (1 - A1);
    �� A1������1���޽�...
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
	if(v[x].size()==0&&fa!=-1){ //Ҷ�ӽ�� 
		A[x]=k[x];
		B[x]=1-k[x]-e[x];
		C[x]=1-k[x]-e[x];
		return true;
	}
	//��Ҷ�ӽ�� 
	A[x]=k[x];
	B[x]=(1-k[x]-e[x])/v[x].size();
	C[x]=1-k[x]-e[x];
	double tmp=0;//�ߵ����ӵļ��� 
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
