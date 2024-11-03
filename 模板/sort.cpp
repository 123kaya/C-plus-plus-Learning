#include<bits/stdc++.h>
using namespace std;


bool cmp(int x, int y) {
	return x>y;  //降序，前面的大于后面的
}

bool cmp2(int x, int y) {
	return x<y;  //升序，前面的小于后面的
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
