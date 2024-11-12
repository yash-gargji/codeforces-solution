#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,v;
        cin>>n>>m>>v;
       vector<pair<int,int>>k;
       int arr[n];
       int ans = 0;
       for(int i = 0;i<n;i++){
          cin>>arr[i];
       }
       for(int i = 0;i<n;i++){
          int sum = 0;
          int ind = i;
          for(int j = i;j<n;j++){
              sum += arr[j];
              i = j;
              if(sum >= v && k.size() < m)
                break;
          }
            k.push_back({ind,sum});
       }
       int size = k.size();
       if(k[k.size() - 1].second < v)
          size--;
       if(size < m){
          cout<<"-1\n";
          continue;
       }
       else if(k.size() )
        for(int i = k.size() - 1;i >= 0;i--){
            ans = max(ans,k[i].second);
            while(k[i].second - arr[k[i].first] >= v){
                int ind = k[i].first;
                if(i-1 >= 0)
                  k[i-1].second += arr[ind];
                k[i].second -= arr[ind];
                k[i].first++;
            }
        }
         int num = 0;
         for(int i = 0;i<k[0].first;i++){
            num += arr[i];
         }
        
          
    }
    
}