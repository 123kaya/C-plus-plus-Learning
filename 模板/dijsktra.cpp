#include<bits/stdc++.h>

using namespace std;
#define x first
#define y second

const int N=1010;
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greator<PII>> heap;
int dist[N];//注意初始化INF 
bool st[N];//注意初始化false 

void dijsktra(int s){
	dist[s]=0;
	heap.push({dist[s], s});
	
	while(heap.size()){
		PII t=heap.top();
		heap.pop();
		
		if(st[t.y])continue;
		st[t.y]=true;//选中（出队）后才标记 
		for(int i=h[t.y]; i!=-1; i=ne[i]){//扩展该节点连接的节点，但扩展不等于选中 
			int j=e[i];
			if(dist[j] > dist[t.y]+w[i]){
				dist[j]=dist[t.y]+w[i]; 
				heap.push({dist[j], j});
			}
		}
	}
} 

