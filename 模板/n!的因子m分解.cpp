#include<bits/stdc++.h>
using namespace std;

void get(int n, int m){
	int result=0;
	while(n){
		result+=n/m;
		n/=m;
	}
	printf("%d %d\n",m, result);
}
