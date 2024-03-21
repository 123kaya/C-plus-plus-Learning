#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0x3fffffff
using namespace std;
typedef long long ll;
int area[1001][1001];
int closepoint[1001];//用来存储已经加入最小生成树的点
int minload[1001];//用来存储最小生成树到其他点的最小权值
//当minload[i] == 0说明已经加入到最小生成树，树内距离为零
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
	for(int i = 1; i <= N; i++){//初始化开始节点
		closepoint[i] = 1;
		minload[i] = area[1][i];
	}
	minload[1] = 0;
	for(int i = 2; i <= N; i++){//一共需要遍历N-1个边
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
		for(int j = 1; j <= N; j++){//修改现在的生成树权值最小边和其出发节点
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
