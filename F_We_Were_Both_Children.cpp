 #include <bits/stdc++.h>
using namespace std;
 #define ll long long int
  
int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--){

         ll n;
          cin>>n;
           
          map<ll,ll>m,m1;
          for(int i = 0;i<n;i++){
                   ll num;
                   cin>>num;
                  if(num <= n){
                     m[num]++;
                  }      
          }
        ll ans = 0;
        
        for(auto value: m){

            ll a = value.first;
            ll b = value.second;

            for(ll i = a;i <= n;i += a){
                 m1[i] += b;
                 ans = max(ans,m1[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}