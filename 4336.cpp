#include<bits/stdc++.h>
using namespace std;

const int N=20;
int n;
double dp[1<<N];//������״ѹ �����״̬����Ҫ������� 
double p[N];

int main(){
	while(~scanf("%d",&n)){
		double pp=0;
		for(int i=0;i<n;i++){
			scanf("%lf",&p[i]);
			pp+=p[i];
		}
		memset(dp,0,sizeof(dp));
		pp=1-pp;//�鲻���Ƶĸ��� 
		dp[(1<<n)-1]=0;//1111ʱ����ȫ���ˣ�����Ҫ������Ϊ0 
		for(int i=(1<<n)-2;i>=0;i--){
			double x=0;
			double s=1;//��һ��
			for(int j=0;j<n;j++){//��������״̬ 
				if(i&(1<<j)) x+=p[j];//�����
				else s+=p[j]*dp[i|(1<<j)];//������û�����״̬������(������) 
			} 
			dp[i]=s/(1-pp-x);//������/�鵽û������ĸ��� 
		}
		printf("%.4lf\n",dp[0]);
	}
	return 0;
}
