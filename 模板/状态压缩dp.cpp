#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=12, M=1<<10, K=110;
int n, k;
int cnt0b[M];//������1�ĸ���

vector<int> st, head[M];//st: �Ϸ�״̬��head 

LL dp[N][K][M];//������i��, �Ѱڷ�j�������аڷ�״̬Ϊl 
bool check(int x){//�д���check 
	return !(x & (x<<1));
}

bool checkL(int a, int b){//�д���check 
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
	for(int i=0; i<1<<n; i++)//����: ��һ��Ԥ����Ϸ�������״̬ 
		if(check(i))st.push_back(i);
	
	for(int a: st)//����: Ԥ������a�Ϸ������� 
		for(int b: st){
			if(checkL(a, b))head[a].push_back(b);
		} 
	
	dp[0][0][0]=1;//ʲô������Ҳ��һ�ַ��� 
	for(int i=1; i<=n+1; i++)
		for(int j=0; j<=k; j++)
			for(int a: st)
				for(int b: head[a]){
					if(count(a)<= j){
						//����״̬Ϊaʱ, ��һ�����п��ܵ�״̬b 
						dp[i][j][a] += dp[i-1][j- count(a)][b];
					}
				} 
				
	printf("%lld\n",dp[n+1][k][0]);
	return 0;
}
