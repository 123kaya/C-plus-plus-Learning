#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool flag;
bool cmp(string a, string b) {
	if(a.size() == b.size())
	return a >= b;
	if(a.size() > b.size()){
		return true;
	}
	return false;
}

vector<int> mul(vector<int> a, vector<int> b) {
	vector<int> c( a.size()+b.size()+1);

	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < b.size(); j++) {
			int k = i+j;
			c[k] += a[i]*b[j];

			if(c[k] > 9) {
				c[k+1] += c[k]/10;
				c[k] %= 10;
			}
		}
	}

	int len = c.size();
	while(c[len-1] == 0&&len > 1){
		c.pop_back();
		len--;
	} 

	return c;
}

vector<int> sub(vector<int> a, vector<int> b) {
	for(int i = 0; i < b.size(); i++) {
		if(a[i] < b[i]) {
			a[i+1]--;
			a[i] += 10;
		}
		a[i] -= b[i];
	}
	int lenb = b.size();
	/*避免a[lenb]为负数，而没有借位处理*/
	while(a[lenb] < 0 && lenb < a.size()){
		a[lenb+1]--;
		a[lenb]+=10;
		lenb++;
	}
	int len = a.size();
	while(a[len-1] == 0 && len > 1) {
		a.pop_back();
		len--;
	}
	
	return a;
}
int main() {
	string aa,bb;
	cin >> aa >> bb;
	string a , b;
	a = "";
	b = "";
	if(aa[0] == '-')
		for(int i = 1; i < aa.length(); i++) a+=aa[i];
	else a = aa;
	if(bb[0] == '-')
		for(int i = 1; i < bb.length(); i++) b+=bb[i];
	else b = bb;
	flag = cmp(a,b);

	vector<int> A,B;

	for(int i = a.size()-1; i>= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size()-1; i>= 0; i--) B.push_back(b[i] - '0');

	A = mul(A,A);
	B = mul(B,B);

//	for(int i = A.size()-1; i >= 0; i--) {
//		cout << A[i];
//	}
//	cout <<endl;
//	for(int i = B.size()-1; i >= 0; i--) {
//		cout << B[i];
//	}
	vector<int> c;
	if(flag) c = sub(A,B);
	else {
		cout << "-";
		c = sub(B,A);
	}
	for(int i = c.size()-1; i >= 0; i--) {
		cout << c[i];
	}
	cout << endl;
	return 0;
}
