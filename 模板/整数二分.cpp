#include<bits/stdc++.h>
using namespace std;

//����������ѡ���������� 
bool check(int x){
	return true;
}

//���仮��Ϊ [l, mid] and [mid+1, l] 
//������������Сֵ 
int bsearch_1(int l, int r){
	while(l < r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	
	return l;
}

//���仮��Ϊ[l, mid-1]��[mid, r]
//�������������ֵ 
int bsearch_2(int l, int r){
	while(l < r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r= mid-1;
	}
	
	return l;
} 
