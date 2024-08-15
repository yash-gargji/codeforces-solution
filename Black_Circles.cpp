#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
     int t;
     cin>>t;

     while(t--){
        int n;
        cin>>n;
        vector<pair<ll,ll>>v(n);

        for(int i = 0;i<n;i++){
            cin>>v[i].first>>v[i].second;
        }
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        ll dis = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

        int ans = 1;

        for(int i = 0;i<n;i++){
            ll a = v[i].first;
            ll b = v[i].second;
            ll num = (x2 - a)*(x2 - a) + (y2 - b)*(y2 - b);
            if(num <= dis){
                ans = 0;
                break;
            }
        }
        if(ans ){
             cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
     }
}