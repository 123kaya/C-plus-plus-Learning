#include<bits/stdc++.h>

queue<int> qe;
void spfa(int s) {
	dist[s]=0;
	qe.push(s);
	/*
	for(int i=0;i<n;i++){//���е���� 
	st[i]=true;
	Q.push(i);
	}
	*/
	while(q.size()) {
		int t=qe.front();
		qe.pop();

		st[t]=false;

		for(int i=h[t]; i!=-1; i=ne[i]) {
			int j=e[i];
			if(dist[j]>dist[t]+w[i]) {
				dist[j]=dist[t]+w[i];
				/*
				cns[j]=cns[t]+1;//1-j���·����1-t��t-j����
				if(cns[j]>n-1) return true;//���������1-n�����ı������Ϊn-1
				*/
				if(!st[j]) {
					qe.push(j);
					st[t]=true;
				}
			}
		}
	}
}
