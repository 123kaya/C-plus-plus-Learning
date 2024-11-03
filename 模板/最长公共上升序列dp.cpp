/*dp[i]表示以某一方向，到达i点最长上升序列
dp[i]可以从1,2...i-1, 转移过来， 可以由i=1开始，递归求出dp 1,2,..i的大小 
*/
int solve(int n){
	int res=0;
	for(int i=1; i<=n; i++){
		dp[i]=1;
		for(int j=1; j<i; j++){
			if(h[i]>h[j])
			dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	for(int i=n; i>=1; i--){
		dp[i]=1;
		for(int j=n; j>i; j--){
			if(h[i]>h[j])
			dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	return res;
}
