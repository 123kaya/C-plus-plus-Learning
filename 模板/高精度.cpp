#include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> A, vector<int> B){
	if(A.size() < B.size()) return  add(B,  A);
	
	vector<int> C;
	int t=0;
	for(i=0; i < A.size(); i++){
		t+=A[i];
		
		if(i < B.size()) t+=B[i];
		
		C.push_back(t%10);
		t/=10;
	}
	
	//若B+A最高位进位，其进位必定小于10 
	if(t!=0) C.push_back(t);
	
	return C;
}
