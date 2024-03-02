#include<iostream>
#include<cstdio>
#define mini -1000
using namespace std;
int N;
struct result{
	int left;
	int right;
	int sum;
	
	result(int l=0, int r=0, int s=0){
		left = l;
		right = r;
		sum = s;
	}
};
result Find_cross(int a[], int left, int mid, int right){
	int left_sum = mini;
	int right_sum = mini;
	
	int low_left = 0;
	int high_right = 0;
	int sum = 0;
	for(int i = mid; i >= left; i--){
		sum+=a[i];
		if(sum > left_sum){
			left_sum = sum;
			low_left = i;
		}
	}
	sum = 0;
	for(int i = mid+1; i <= right; i++){
		sum+=a[i];
		if(sum > right_sum)
			right_sum = sum;
			high_right = i;
	}
	result R(low_left,high_right,left_sum+right_sum);
	return R;
}
result solve(int a[], int left, int right){
	if(left >= right){
		result r(left,right,a[left]);
		return r;
	}
	int mid = (left+right)/2;
	
/*第一次问题出现在这里，
  N =（right-left+1）;
  这只能算元素数量，只有当 left 恒为 0 时才可以使用
  
  mid = (right - left + 1) /2;
*/
  
	result result_left = solve(a, left, mid);
	result result_right = solve(a, mid+1, right);
	result result_cross = Find_cross(a, left, mid, right);
	
	if(result_left.sum >= result_right.sum && result_left.sum >= result_cross.sum)
		return result_left;
	else if(result_right.sum >= result_left.sum && result_right.sum >= result_cross.sum)
		return result_right;
	else
		return result_cross;
}
int main(){
	cin >> N;
	int a[N];
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	result r = solve(a, 0, N-1);
	
	printf("low = %d,  high = %d,  sum = %d\n",r.left,r.right,r.sum);
	return 0;
}
