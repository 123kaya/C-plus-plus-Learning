#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;

ll a[1000001];
int N;
ll dp[1000001];
ll ans = -100000;
int main(){
	dp[0] = -1000000;
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		scanf("%lld",&a[i]);
	}
	/*dp[i]用来记录有效序列和，若dp[i-1]+a[i] > a[i]则称dp[i-1]有效

	  ans用来记录最大的有效序列和，即为连续最大子序列*/
	for(int i = 1; i <= N; i++){
		if(dp[i-1]+a[i] > a[i]){
			dp[i] = dp[i-1]+a[i];
		}
		else dp[i] = a[i];
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}
