//K倍区间 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;

int n;
ll cnt;
int A[N];
ll S[N];
int K;
int X[N];//代表mod K余数为i的S[i] 


int main(){
	scanf("%d%d",&n,&K);
	for(int i=1; i<=n; i++){
		scanf("%d",&A[i]);
		S[i]=S[i-1]+A[i];
	}
	
	//因为对于S[i]mod K==0的情况下，每一个非空集合都是K倍区间，即
	//a,b,c....都与空集合组合成为一个解 
	for(int i=1; i<=n; i++){
		
		cnt+=X[S[i]%K]++;
		cout << cnt << endl;
	}
	cout << cnt << endl;
	return 0;
}
