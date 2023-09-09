#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
         char arr[8][8];

         for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                 cin>>arr[i][j];
            }
         }
         string s;
         for(int i = 0;i<8;i++){
            for(int j =0;j<8;j++){
                 if(arr[j][i] != '.'){
                    s = s + arr[j][i];
                 }
            }
         }
         cout<<s<<endl;

    }
    
}