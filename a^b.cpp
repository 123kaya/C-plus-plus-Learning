#include<iostream>
using namespace std;
typedef long long ll;
int re = 1;
int main(){
    int a,b,p;
    cin >> a >> b >> p;
    while(b){
        if(b&1) re = re*a%p;
        b >>= 1;
        a = a*a%p;
    }
    cout << re << endl;
    return 0;
}
