#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>mat(n);
    int d[n][m][4];
    int move[n][m][4];
    memset(d,INT_MAX,sizeof(d));
    memset(move,INT_MAX,sizeof(d));
    
    for(int i = 0;i<n;i++){
        cin>>mat[i];
    }
    int sr = -1,sc = -1;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j] == 'S'){
               sr = i;
               sc = j;
            }
        }
    }
    move[sr][sc][0] = 0,d[sr];
    
}