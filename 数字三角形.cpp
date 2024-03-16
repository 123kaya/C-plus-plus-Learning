#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
int line;
ll a[1001][1001];

int main(){
	scanf("%d",&line);
	for(int i = 1; i <= line; i++){
		for(int j = 1; j <= i; j++){
			scanf("%lld",&a[i][j]);
		}
	}

	for(int i = line-1; i >= 1; i--){
		for(int j = 1; j <= i; j++){
			a[i][j] = max(a[i+1][j],a[i+1][j+1]) + a[i][j];
		}
	}

	printf("%lld\n",a[1][1]);
	return 0;
}
