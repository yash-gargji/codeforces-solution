#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        char m[n][n];

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>m[i][j];
            }
        }
        char ans[n/k][n/k];
        int x = 0;
        int y = 0;

        for(int i = 0;i<n;i += k){
            for(int j = 0;j<n;j += k){
                if(m[i][j] == '1'){
                  ans[x][y++] = '1';
                }
                else 
                    ans[x][y++] = '0';
            }
           x++;
           y = 0;
        }
        for(int i = 0;i<n/k;i++){
            for(int j = 0;j<n/k;j++){
                 cout<<ans[i][j];
            }
          cout<<endl;
        }
    }
}