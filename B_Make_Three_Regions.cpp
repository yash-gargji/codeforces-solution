#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         vector<string>v(2);
         cin>>v[0]>>v[1];
         int ans = 0;

         for(int i = 1;i<n-1;i++){
            if (v[0][i] == '.' && v[0][i - 1] == '.' && v[0][i + 1] == '.' && v[1][i] == '.' && v[1][i - 1] == 'x' && v[1][i + 1] == 'x') {
                ans++;
            }
            if (v[1][i] == '.' && v[1][i - 1] == '.' && v[1][i + 1] == '.' && v[0][i] == '.' && v[0][i - 1] == 'x' && v[0][i + 1] == 'x') {
               ans++;
            }
         }
        
       
      cout<<ans<<endl;
    }
}