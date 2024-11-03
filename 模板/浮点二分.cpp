#include<bits/stdc++.h>
using namespace std;

const double eps=1e-6;

// 需要注意精度和数据类型 
double bsearch_3(double l, double r) {
	while(r-l > eps) {
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}

	return l;
}
