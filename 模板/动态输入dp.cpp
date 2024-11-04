/*1022. 宠物收服*/
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
背包问题优化
对于动态输入的背包问题，只能从后向前遍历

因为第i层的结果依赖于 第i-1层的结果，
从前向后变化，则会用第i层结果覆盖第i-1层结果
则dp[i][j]后面的转移，实则是用第i层的结果代替了第i-1层的结果，造成错误 
*/

