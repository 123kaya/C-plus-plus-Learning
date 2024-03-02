#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int ans = 0;
int n;
bool check(int deep,int m) {
	for(int k = 0; k < n ; ++ k) {
		if(a[k][m]) return false;
	}
	// 检查所有方向以判断皇后是否会攻击
	//下方还没有放置皇后，所以不用检查
	for(int i = 1; i <= deep; i++) {
		if(a[deep - i][m]) return false; // 检查上方
		if(m - i >= 0 && a[deep - i][m - i]) return false; // 检查左上方
		if(m + i < n && a[deep - i][m + i]) return false; // 检查右上方
	}
	return true;
}
void dfs(int deep) {
	if(deep == n) {
		ans++;
		return;
	}
	for(int i = 0; i < n ; ++ i) {
		if(check(deep,i)) {
			a[deep][i] = 1; // 放置皇后
			dfs(deep+1);
			a[deep][i] = 0; // 移除皇后
		}
	}
}
int main() {
	cin>>n;
	dfs(0);
	cout<<ans;
	return 0;
}
