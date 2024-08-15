#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,s,m;
         cin>>n>>s>>m;
         vector<pair<int,int>>v(n);

         for(int i = 0;i<n;i++){
             cin>>v[i].first>>v[i].second;
         }
         sort(v.begin(),v.end());
         int prev = 0;
         int num = 0;

         for(int i = 0;i<n;i++){
             num = max(num,v[i].first - prev);
             prev = v[i].second;
         }
         num = max(num,m - prev);
         if(num >= s)
           cout<<"YES\n";
        else{
             cout<<"NO\n";
        }
    }
}