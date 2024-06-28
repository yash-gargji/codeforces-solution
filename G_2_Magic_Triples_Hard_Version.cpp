#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int t;
     cin>>t;

     vector<int>v;
     int num = 2;
     while(num*num <= 1e9){
        v.push_back(num);
        num++;
     }

     while (t--){
          int n;
          cin>>n;
          map<long long ,long long>mp;
          long long int ans = 0;

          for(int i = 0;i<n;i++){
              long long k;
              cin>>k;
              mp[k]++;
          }
          for(auto it = mp.begin(); it != mp.end(); it++){
              for(int i = 0;i<v.size();i++){
                 if(v[i] > it->first){
                     break;
                 }
                 else if(it->first % (v[i]*v[i]) == 0){
                      if(!mp.count(it->first/v[i]) || !mp.count(it->first/(v[i]*v[i]))){
                         continue;
                      }
                    ans += it->second*mp[it->first/v[i]]*mp[it->first/(v[i] * v[i])];
                 }
              }
             ans += it->second*(it->second-1)*(it->second - 2);
          }
        cout<<ans<<endl;
     }
}