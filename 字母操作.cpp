#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	char a;
	cin >> a;

	/*�ж��Ƿ�����ĸ��������ĸ����0���Ǵ�д��ĸ����1
	  ��Сд��ĸ����2*/
//	cout << isalpha(a) << endl;
	/*תΪСд��ĸ*/
//  cout << (char)tolower(a) << endl;
    /*תΪ��д��ĸ*/
	cout << (char)toupper(a) << endl;
	return 0;
}
