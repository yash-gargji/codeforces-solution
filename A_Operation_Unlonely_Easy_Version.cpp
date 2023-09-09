#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
         int r,c;
         cin>>r>>c;
         char arr[r][c];
       int flag  = 1;
         for(int i = 0;i<r;i++){
             for(int j = 0;j<c;j++){
                    cin>>arr[i][j];
                    
             }
         }
         
         if(r ==  1 ||  c == 1){
                for(int i = 0;i<r;i++){
             for(int j = 0;j<c;j++){
                     if(arr[i][j] == '^'){
                        cout<<"NO\n";
                        return 0;
                     }
                    
             }
         }
         
         }
            cout<<"YES\n";
         
        
}