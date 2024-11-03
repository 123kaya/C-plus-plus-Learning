/*dp[i]��ʾ��ĳһ���򣬵���i�����������
dp[i]���Դ�1,2...i-1, ת�ƹ����� ������i=1��ʼ���ݹ����dp 1,2,..i�Ĵ�С 
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
