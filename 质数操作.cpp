#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int a;

//�����ж�
bool is_prime(int n){
	if(n < 2) return false;
	if(n == 2) return true;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

//�ֽ�Ϊ������
void divid(int x){
	/*���ж����Ƿ��������������ָ����forѭ����
       �������ֱ�����x��
       
       �����������ᱻ�ֽ�Ϊ2��3��5��7��11��������
       ����������˹��ɷ����������������һ������������*/
	for(int i = 2; i*i <= x; i++){
		if(x % i == 0){
			int s = 0;
			while(x % i == 0) x /= i, s++;
			cout << i << " " << s << endl;
		}
	}
	
	/*��Ϊ������һ��sqrt��x������ѭ���ڲ�һ��������������
      ��if����ж�*/
	if(x > 1) cout << x <<" " << 1 << endl;
}
int main(){
	cin >> a;
	cout << is_prime(a) << endl;
	divid(a);
	return 0;
}
