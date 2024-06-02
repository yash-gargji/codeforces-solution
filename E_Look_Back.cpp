#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n ,ans = 0;
        cin>>n;
        vector<double>v(n);

        for(int i = 0;i<n;i++){
             cin>>v[i];
        }
        for(int i = 1; i<n;i++){
             while(v[i] <  v[i-1]){
              ans ++;
              v[i] = v[i]*2;
            }
        }
      cout<<ans<<endl;
    }
}