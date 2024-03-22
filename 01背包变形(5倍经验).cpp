#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define NUM 1100
typedef long long ll;
using namespace std;
int n;
int have;
int lose[NUM];
int win[NUM];
int use[NUM];

ll dp[NUM][NUM];
int main(){
	scanf("%d%d",&n,&have);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d%d",&lose[i],&win[i],&use[i]);
	}

	for(int i = 1; i <= n; i++){
/*����Ϊʲôj��0��ʼ�أ�*/
/*���������j���������е�ҩƷ��
   ��j==0ʱ����Ȼû��ҩƷ������ʱ�ľ���ֵ��һ��Ϊ0
   ���j��1��ʼ��ôdp[i][0]����ı�״̬����Ϊ0�������
*/
		for(int j = 0; j <= have; j++){
			if(j >= use[i])
			dp[i][j] = max(dp[i-1][j]+lose[i],dp[i-1][j-use[i]]+win[i]);
			else
			dp[i][j] = dp[i-1][j]+lose[i];
		}
	}
	ll sum = dp[n][have]*5;
	printf("%lld\n",sum);
	return 0;
}
