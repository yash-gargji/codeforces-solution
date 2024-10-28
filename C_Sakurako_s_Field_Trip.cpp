#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
         
        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
       int ans = 0;
        vector<pair<int,int>>v;
        for(int i = 0;i<n/2;i++){
            v.push_back({arr[i],arr[n - i - 1]});
        }
        if(n % 2 == 0 && v[n/2-1].first == v[n/2-1].second)
          ans++;
        if(n % 2)
          v.push_back({arr[n/2],arr[n/2]});

          for(int i = 0;i<v.size()-1;i++){  
              if(v[i].first == v[i].second){
                if(v[i+1].first == v[i].first)
                  ans++;
                if(v[i+1].second == v[i].first)
                  ans++;
              }
              else if(v[i+1].first == v[i+1].second){
                if(v[i].first == v[i+1].first)
                  ans++;
                if(v[i].second == v[i+1].first)
                  ans++;
              }
          }
        cout<<ans<<endl;
    }
}