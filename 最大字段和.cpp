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
	/*dp[i]������¼��Ч���кͣ���dp[i-1]+a[i] > a[i]���dp[i-1]��Ч

	  ans������¼������Ч���кͣ���Ϊ�������������*/
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
