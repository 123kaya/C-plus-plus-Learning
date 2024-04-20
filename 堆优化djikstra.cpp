#include<bits/stdc++.h>
using namespace std;
  
#define c first
#define a second
typedef pair<int, int > PII;
const int N=2510;

const int M=6210;// ��������
 
//ͷ�ڵ㣬�����ӵı߱�ţ��ߵ�Ȩֵ����һ���ߵ��±� 
int h[N],e[2*M], w[2*M], ne[2*M];
int T,C,Ts,Te;
priority_queue<PII, vector<PII>, greater<PII>> qe;
int dist[N];
bool st[N];
int idx;
void add(int a, int b, int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

//���Ż���djikstra�㷨 
void djikstra(int s){
	
	//��ʼ�� 
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	qe.push({0,s});
	while(qe.size()){
		auto t=qe.top();
		qe.pop();
		//��� 
		if(st[t.a])continue;
		st[t.a]=true;
		//���� 
		for(int j=h[t.a]; j!=-1; j=ne[j]){
			int k=e[j];
			if(dist[k]>dist[t.a]+w[j]){
				
				dist[k]=dist[j]+w[t.c];
				qe.push({dist[k],k});
			}
		}
	}
} 
int main(){
	cin >> T >> C >> Ts >> Te;
	memset(h,-1, sizeof(h));
	while(C--){
		int a, b, c;
		cin>> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}
	
	djikstra(Ts);
	cout << dist[Te] << endl;
	return 0;
}
