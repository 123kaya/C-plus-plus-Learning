#include<bits/stdc++.h>

using namespace std;
#define x first
#define y second

const int N=1010;
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greator<PII>> heap;
int dist[N];//ע���ʼ��INF 
bool st[N];//ע���ʼ��false 

void dijsktra(int s){
	dist[s]=0;
	heap.push({dist[s], s});
	
	while(heap.size()){
		PII t=heap.top();
		heap.pop();
		
		if(st[t.y])continue;
		st[t.y]=true;//ѡ�У����ӣ���ű�� 
		for(int i=h[t.y]; i!=-1; i=ne[i]){//��չ�ýڵ����ӵĽڵ㣬����չ������ѡ�� 
			int j=e[i];
			if(dist[j] > dist[t.y]+w[i]){
				dist[j]=dist[t.y]+w[i]; 
				heap.push({dist[j], j});
			}
		}
	}
} 

