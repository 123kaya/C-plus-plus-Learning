#include<bits/stdc++.h>
using namespace std;


bool cmp(int x, int y) {
	return x>y;  //����ǰ��Ĵ��ں����
}

bool cmp2(int x, int y) {
	return x<y;  //����ǰ���С�ں����
}
// [first, last)
int a[10]= {5,2,1,3,5,2,1,3,4,8};

int main() {
	sort(a, a+10 , cmp);
	for(int i=0; i<10; i++) {
		printf("%d   ",a[i]);
	}
	cout << endl;
	return 0;
}
