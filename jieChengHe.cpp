#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int last[1000];
int sum[1000];
int len;
int lens;
void multi(int* a, int k) {
	len = 1000;
	while(a[len-1] == 0) {
		len--;
	}
	
	// 不能直接乘以a[i+1] += a[i]/10
	
	/* 后面在执行a[i]*=k时，会将a[i] 向a[i+1]的进位也
	   乘以k，而发生错误 */
	for(int i = 0; i <= len; i++) {
		a[i] *= k;
		//cout << a[1] << "--";
		if(a[i-1] > 9||i >= 1) {
			a[i] += a[i-1]/10;
			a[i-1] %= 10;
		}
	}
	while(a[len]!=0) {
		if(a[len] > 9) {
			a[len+1] += a[len]/10;
			a[len] %= 10;
		}
		len++;
	}

//	for(int i = len-1; i >= 0; i--)
//		printf("%d",a[i]);
//	cout << "@" << k<<endl;
}

void add(int* su, int* a) {
	lens = max(len, lens);

	for(int i = 0; i < lens; i++) {
		su[i] += a[i];
		if(su[i] > 9) {
			su[i+1] += su[i]/10;
			su[i] %= 10;
		}
	}

	while(su[lens]!=0) {
		if(su[lens] > 9) {
			su[lens+1] += su[lens]/10;
			su[lens] %= 10;
		}
		lens++;
	}
}
int main() {
	cin >> n;
	last[0] = 1;

	for(int i = 1; i <= n; i++) {
		multi(last, i);
		add(sum, last);
	}


	for(int i = lens-1; i >= 0; i--) {
		printf("%d", sum[i]);
	}
	cout <<endl;
	return 0;
}
