#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int ans = 0;
int n;
bool check(int deep,int m) {
	for(int k = 0; k < n ; ++ k) {
		if(a[k][m]) return false;
	}
	// ������з������жϻʺ��Ƿ�ṥ��
	//�·���û�з��ûʺ����Բ��ü��
	for(int i = 1; i <= deep; i++) {
		if(a[deep - i][m]) return false; // ����Ϸ�
		if(m - i >= 0 && a[deep - i][m - i]) return false; // ������Ϸ�
		if(m + i < n && a[deep - i][m + i]) return false; // ������Ϸ�
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
			a[deep][i] = 1; // ���ûʺ�
			dfs(deep+1);
			a[deep][i] = 0; // �Ƴ��ʺ�
		}
	}
}
int main() {
	cin>>n;
	dfs(0);
	cout<<ans;
	return 0;
}
