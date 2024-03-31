#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#define N 100010
using namespace std;
typedef vector<int> v;

int n;
string xt;
string yt;
v x;
v y;

int dp[N][2];//0为add，1为minus
int main(){
	scanf("%d",&n);
	cin >> xt >> yt;

	for(int i = 0; i < n; i++){
		x.push_back(xt[i]-'0');
		y.push_back(yt[i]-'0');
	}

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	
	dp[0][0] = (y[0]-x[0]+10)%10;//从x加到y
	dp[0][1] = (x[0]-y[0]+10)%10;//从x减到y,等价于从y加到x
	for(int i = 1; i < n; i++){
 /*dp[i][0]会接受来自于dp[i-1][0]的进位，
   来自dp[i-1][1]的借位
   而进位和借位是对于x而言的，进位的话在dp[i][0]加法中
   相当于y-(x+ans)= y-x-ans
   借位相当于y-(x-ans)= y-x+ans
   
   dp[i][k]的加减是对相同层次的x、y进行的，同时累加上一状态
 */
		dp[i][0] = min((y[i]-x[i]-(y[i-1]<x[i-1])+10)%10+dp[i-1][0]
        ,(y[i]-x[i]+(x[i-1]<y[i-1])+10)%10+dp[i-1][1]);
        
/* 同理，对于减法来说, dp[i][1]接受进位时相当于 (x+ans)-y= x-y+ans
   被退位时相当于(x-ans)-y = x-ans-y;
*/
        dp[i][1] = min((x[i]-y[i]+(y[i-1]<x[i-1])+10)%10+dp[i-1][0]
        ,(x[i]-y[i]-(x[i-1]<y[i-1])+10)%10+dp[i-1][1]);
	}
	printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
}
