/*1022. �����շ�*/
#include<bits/stdc++.h>
using namespace std;

const int N=1010, M=510, K=110;
int dp[N][M];

int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);

	int nu, hr;
	

	
	for(int i=1; i<=k; i++){
		scanf("%d%d",&nu, &hr);
		for(int j=n; j>=nu; j--)
			for(int h=m-1; h>=hr; h--){
				dp[j][h]=max(dp[j][h], dp[j-nu][h-hr]+1);
			}
	}
	
	
	int p=m-1;
	while(dp[n][m-1]==dp[n][p]&&p>=0)p--;
	printf("%d\n",m-(p+1));
	return 0;
}


/*
���������Ż�
���ڶ�̬����ı������⣬ֻ�ܴӺ���ǰ����

��Ϊ��i��Ľ�������� ��i-1��Ľ����
��ǰ���仯������õ�i�������ǵ�i-1����
��dp[i][j]�����ת�ƣ�ʵ�����õ�i��Ľ�������˵�i-1��Ľ������ɴ��� 
*/

