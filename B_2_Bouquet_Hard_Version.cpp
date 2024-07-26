#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         long long int n,m;
         cin>>n>>m;
         vector<pair<long long,long long>>v(n);

         for(int i = 0;i<n;i++){
             cin>>v[i].first;
         }
         for(int i = 0;i<n;i++){
             cin>>v[i].second;
         }
         sort(v.begin(),v.end());
         long long ans = 0;

         for(int i = 0;i<n;i++){
             ans = max(ans,min(v[i].second,m/v[i].first) * v[i].first);
             if(i == n-1 || v[i].first - v[i+1].first != -1)
                  continue;
              long long sum = 0;
              long long a = min(v[i].second,m/v[i].first);
              sum += 1ll*a*v[i].first;
              long long b = min(v[i+1].second,(m - sum)/v[i+1].first);
              sum += b*v[i+1].first;
              int extra = min({v[i+1].second - b, m - sum,a});
              ans = max(ans,sum+extra);
         }
        cout<<ans<<endl;
    }
}