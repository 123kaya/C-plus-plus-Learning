//K������ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;

int n;
ll cnt;
int A[N];
ll S[N];
int K;
int X[N];//����mod K����Ϊi��S[i] 


int main(){
	scanf("%d%d",&n,&K);
	for(int i=1; i<=n; i++){
		scanf("%d",&A[i]);
		S[i]=S[i-1]+A[i];
	}
	
	//��Ϊ����S[i]mod K==0������£�ÿһ���ǿռ��϶���K�����䣬��
	//a,b,c....����ռ�����ϳ�Ϊһ���� 
	for(int i=1; i<=n; i++){
		
		cnt+=X[S[i]%K]++;
		cout << cnt << endl;
	}
	cout << cnt << endl;
	return 0;
}
