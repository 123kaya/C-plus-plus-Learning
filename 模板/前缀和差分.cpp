//ǰ׺��
int x;
for(int i=1; i<=n; i++){
	cin >> x;
	s[i]=s[i-1]+x;
} 

//ǰ׺����
for(int i=1; i<=n; i++){
	for(int j=1; j<=m; j++){
		cin >> x;
		s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1] + x;
	}
} 

//���
for(int i=1; i<=n; i++){
	cin >> a[i];
	b[i]=a[i]-a[i-1];
} 

while(m--){
	int l,r,c;
	cin >> l >> r >> c;
	
	b[l]+=c;
	b[r+1]-=c;
}

//��־���
void insert(int x1, int y1, int x2, int y2, int c){
	a[x1][y1]+=c;
	a[x1][y2+1]-=c;
	a[x2+1][y1]-=c
	a[x2+1][y2+1]+=c;
} 








 
