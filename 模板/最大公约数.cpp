#include<bist/stdc++.h>
using namespace std;


//a%0, return a;
int gcd(int x, int y){
	int s;
	while(y){
		s=x%y;
		x=y;
		y=s;//y=s=0, return x;
	}
	
	return x;
}
