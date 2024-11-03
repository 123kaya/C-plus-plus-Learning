#include<bits/stdc++.h>
using namespace std;

//在两个数中选，易于区分 
bool check(int x){
	return true;
}

//区间划分为 [l, mid] and [mid+1, l] 
//满足条件的最小值 
int bsearch_1(int l, int r){
	while(l < r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	
	return l;
}

//区间划分为[l, mid-1]和[mid, r]
//满足条件的最大值 
int bsearch_2(int l, int r){
	while(l < r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r= mid-1;
	}
	
	return l;
} 
