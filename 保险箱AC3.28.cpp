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

int dp[N][2];//0Ϊadd��1Ϊminus
int main(){
	scanf("%d",&n);
	cin >> xt >> yt;

	for(int i = 0; i < n; i++){
		x.push_back(xt[i]-'0');
		y.push_back(yt[i]-'0');
	}

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	
	dp[0][0] = (y[0]-x[0]+10)%10;//��x�ӵ�y
	dp[0][1] = (x[0]-y[0]+10)%10;//��x����y,�ȼ��ڴ�y�ӵ�x
	for(int i = 1; i < n; i++){
 /*dp[i][0]�����������dp[i-1][0]�Ľ�λ��
   ����dp[i-1][1]�Ľ�λ
   ����λ�ͽ�λ�Ƕ���x���Եģ���λ�Ļ���dp[i][0]�ӷ���
   �൱��y-(x+ans)= y-x-ans
   ��λ�൱��y-(x-ans)= y-x+ans
   
   dp[i][k]�ļӼ��Ƕ���ͬ��ε�x��y���еģ�ͬʱ�ۼ���һ״̬
 */
		dp[i][0] = min((y[i]-x[i]-(y[i-1]<x[i-1])+10)%10+dp[i-1][0]
        ,(y[i]-x[i]+(x[i-1]<y[i-1])+10)%10+dp[i-1][1]);
        
/* ͬ�����ڼ�����˵, dp[i][1]���ܽ�λʱ�൱�� (x+ans)-y= x-y+ans
   ����λʱ�൱��(x-ans)-y = x-ans-y;
*/
        dp[i][1] = min((x[i]-y[i]+(y[i-1]<x[i-1])+10)%10+dp[i-1][0]
        ,(x[i]-y[i]-(x[i-1]<y[i-1])+10)%10+dp[i-1][1]);
	}
	printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
}
