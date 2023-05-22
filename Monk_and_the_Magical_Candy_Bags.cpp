#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        multiset<ll>s;
        for(int i = 0;i<n;i++){
            ll num;
            cin>>num;
            s.insert(num);
        }
        ll sum = 0;
        for(int i = 0;i<k;i++){
             auto it (--(s.end()));
             ll num = (*it);
             sum = sum+ num;
             s.erase(it);
             s.insert(num/2);
        }
        cout<<sum<<endl;
    }
    return 0;
}