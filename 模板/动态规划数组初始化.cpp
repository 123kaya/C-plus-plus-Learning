#include<bits/stdc++.h>
using namespace std;

const int N=110;

//ȫ������ĳ�ʼֵΪ0
/*
�ӣ�1��1����ʼ�������ŵ㣺

1������f[i-1 ][j]��Խ��
2����0�к͵�0�г�ʼֵһֱΪ0���ṩ��ʼֵ 
*/ 
int W[N][N], f[N][N];

int main(){
    int T, R, C;
    cin >> T;
    while(T){
        T--;
        cin >> R >> C;
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                cin >> W[i][j];
            }
        }
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1])+W[i][j];
            }
        }
        cout << f[R][C] << endl;
        
    }
    
    return 0;
}
