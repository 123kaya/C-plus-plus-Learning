#include<bits/stdc++.h>
using namespace std;

const double eps=1e-6;

// ��Ҫע�⾫�Ⱥ��������� 
double bsearch_3(double l, double r) {
	while(r-l > eps) {
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}

	return l;
}
