#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> v;
v A;
int n;
int k;


int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		A.push_back(a);
	}
	sort(A.begin(),A.end());
/*unique函数只能对已经有序序列进行去重*/
    v::iterator last = unique(A.begin(),A.end());
    
	
   // Find_Kelement(A,k,0,last-A.begin());	
	if(last-A.begin() < k){
		printf("NO RESULT\n");
		return 0;
	}
	else printf("%d\n",A[k-1]);
	return 0;
}
