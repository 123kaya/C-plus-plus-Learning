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
/*这里为什么j从0开始呢？*/
/*首先清楚，j代表手上有的药品量
   当j==0时，虽然没有药品，但此时的经验值不一定为0
   如果j从1开始那么dp[i][0]不会改变状态，恒为0，则出错
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
