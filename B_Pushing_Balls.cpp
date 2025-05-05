#include<bits/stdc++.h>
using namespace std;

int check(int row,int col,vector<string>&v){
    int a = 0,b = 0;
     
    for(int i = 0;i<row;i++){
        if(v[i][col] == '0'){
           a = 1;
        }
    }
    for(int i = 0;i<col;i++){
        if(v[row][i] == '0')
           b = 1;
    }
    return min(a,b);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>v(n);

        for(int i = 0;i<n;i++){
           cin>>v[i];
        }
        int flag = 0;

        for(int i = 0;i<n;i++){
           for(int j = 0;j<m;j++){
               if(v[i][j] == '0')
                 continue;
              flag = max(flag,check(i,j,v));
           }
        }
        if(flag == 1){
           cout<<"NO\n";
        }
        else{
           cout<<"YES\n";
        }
    }
}