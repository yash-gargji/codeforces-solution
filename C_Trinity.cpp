#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);

        for(int i  =0;i<n;i++){
           cin>>v[i];
        }
        sort(v.begin(),v.end());
        int ans = INT_MAX;

        for(int i = 0;i<n-1;i++){
           auto it = v.end() -  lower_bound(v.begin(),v.end(),v[i] + v[i+1]) ;
           ans = min(ans,i + (int)it);
        }
      cout<<ans<<endl;
    }
}