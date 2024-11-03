#include<bits/stdc++.h>
using namespace std;

const int N=110;

//全局数组的初始值为0
/*
从（1，1）开始存数据优点：

1、避免f[i-1 ][j]的越界
2、第0行和第0列初始值一直为0，提供初始值 
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
