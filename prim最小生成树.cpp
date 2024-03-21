#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0x3fffffff
using namespace std;
typedef long long ll;
int area[1001][1001];
int closepoint[1001];//�����洢�Ѿ�������С�������ĵ�
int minload[1001];//�����洢��С�����������������СȨֵ
//��minload[i] == 0˵���Ѿ����뵽��С�����������ھ���Ϊ��
int N;
int M;
ll sum;
void init(){
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			area[i][j] = INF;
		}
	}
}

int prim(){
	int val = 0;
	for(int i = 1; i <= N; i++){//��ʼ����ʼ�ڵ�
		closepoint[i] = 1;
		minload[i] = area[1][i];
	}
	minload[1] = 0;
	for(int i = 2; i <= N; i++){//һ����Ҫ����N-1����
	int min = INF;
		int k = -1;
		for(int j = 1; j <= N; j++){
			if(minload[j]&& minload[j] <= min){
				min = minload[j];
				k = j;
			}
		}
		minload[k] = 0;
		val = max(min,val);
		sum += min;
		if(k == -1||min == INF) return -1;
		for(int j = 1; j <= N; j++){//�޸����ڵ�������Ȩֵ��С�ߺ�������ڵ�
			if(minload[j] && area[k][j]<minload[j]){
				minload[j] = area[k][j];
				closepoint[j] = k;
			}
		}
	}

	return val;
}
int main(){
	scanf("%d%d",&N,&M);
	init();
	for(int i = 0; i < M; i++){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		area[x][y] = t;
		area[y][x] = t;
	}

	int val = prim();
	cout << val << endl;
	return 0;
}
