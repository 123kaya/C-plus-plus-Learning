#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int a;

//质数判断
bool is_prime(int n){
	if(n < 2) return false;
	if(n == 2) return true;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

//分解为质因子
void divid(int x){
	/*先判断其是否是质数，如果是指数则for循环内
       无输出，直接输出x；
       
       如果非质数则会被分解为2，3，5，7，11等数，且
       质数可以相乘构成非质数，所以输出的一定是质数因子*/
	for(int i = 2; i*i <= x; i++){
		if(x % i == 0){
			int s = 0;
			while(x % i == 0) x /= i, s++;
			cout << i << " " << s << endl;
		}
	}
	
	/*因为至多有一个sqrt（x），但循环内不一定检测出来，所以
      用if语句判断*/
	if(x > 1) cout << x <<" " << 1 << endl;
}
int main(){
	cin >> a;
	cout << is_prime(a) << endl;
	divid(a);
	return 0;
}
