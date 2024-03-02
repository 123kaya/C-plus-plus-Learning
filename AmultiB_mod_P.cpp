#include<iostream>
using namespace std;
typedef long long ll;
ll re = 0;
int main(){
    ll a, b, p;
    cin >> a >> b >> p;
    while(b){
        if(b&1) re = (re+a)%p;
        b >>= 1;
        a = 2*a%p;//b左移后需要更新a；
    }
    re %= p;
    cout << re << endl;
    return 0;
}
