#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
          int n,m;
          cin>>n>>m;
            int k;
            cin>>k;
          map<int,int>mp;
          int a[n],b[m];
          for(int i = 0;i<n;i++){
            cin>>a[i];
             
          }
          for(int i = 0;i<m;i++){
            cin>>b[i];
            mp[b[i]]++;
          }
          map<int,int>p;
            int count = 0;
            int sum = 0;
          for(int i = 0;i<n;i++){
              if(i >= m){
                p[a[i - m]]--;
                if(p[a[i-m]] < mp[a[i-m]]){
                    sum--;
                }
              }
              p[a[i]]++;
              if(p[a[i]] <= mp[a[i]]){
                 sum++;
              }
              if(i >= m-1 && sum >= k){
                 count++;
              }
          }
        cout<<count<<endl;
    }
}