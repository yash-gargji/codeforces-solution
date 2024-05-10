#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
     ll n,m,k;
     cin>>n>>m>>k;
     vector<pair<ll,ll>>vec;
     ll arr[n];
     for(ll i=0;i<n;i++){
        cin>>arr[i];
        vec.pb({arr[i],i});
     }
     sort(vec.begin(),vec.end());

     vector<ll>v(n);
       ll count = 0;
        ll ans = 0;
     for(ll i = 0;i<n;i++){
           ll num = min(m,k - count);
           count = count + num;
          v[vec[i].second] = num;
          ans += 1ll*vec[i].first*num;
     }
     count = 0;
     for(ll i = 0;i<n;i++){
          ans += count*v[i];
          count += v[i];
     }
     cout<<ans<<endl;
     
}
int main() {
    ll t;
    t=1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}