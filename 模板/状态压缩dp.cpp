#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=12, M=1<<10, K=110;
int n, k;
int cnt0b[M];//二进制1的个数

vector<int> st, head[M];//st: 合法状态，head 

LL dp[N][K][M];//摆至第i行, 已摆放j个，该行摆放状态为l 
bool check(int x){//行处理check 
	return !(x & (x<<1));
}

bool checkL(int a, int b){//列处理check 
	return check(a|b) && !(a&b);
} 

int count(int x){
	if(cnt0b[x])return cnt0b[x];
	
	int res=0;
	int tem=x;
	while(tem){
		if(tem&1)res++;
		tem>>=1;
	}
	cnt0b[x]=res;
	return cnt0b[x];
}
int main(){
	scanf("%d%d",&n, &k);
	for(int i=0; i<1<<n; i++)//横向: 第一次预处理合法二进制状态 
		if(check(i))st.push_back(i);
	
	for(int a: st)//竖向: 预处理与a合法相邻行 
		for(int b: st){
			if(checkL(a, b))head[a].push_back(b);
		} 
	
	dp[0][0][0]=1;//什么都不摆也是一种方案 
	for(int i=1; i<=n+1; i++)
		for(int j=0; j<=k; j++)
			for(int a: st)
				for(int b: head[a]){
					if(count(a)<= j){
						//该行状态为a时, 上一行所有可能的状态b 
						dp[i][j][a] += dp[i-1][j- count(a)][b];
					}
				} 
				
	printf("%lld\n",dp[n+1][k][0]);
	return 0;
}
