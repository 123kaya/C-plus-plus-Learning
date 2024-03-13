#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	char a;
	cin >> a;

	/*判断是否是字母，不是字母返回0，是大写字母返回1
	  是小写字母返回2*/
//	cout << isalpha(a) << endl;
	/*转为小写字母*/
//  cout << (char)tolower(a) << endl;
    /*转为大写字母*/
	cout << (char)toupper(a) << endl;
	return 0;
}
