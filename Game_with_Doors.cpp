#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        vector<pair<int,int>>v(2);

        for(int i = 0;i<2;i++){
              cin>>v[i].first;
              cin>>v[i].second;
        }
        sort(v.begin(),v.end());

        if(v[1].first > v[0].second){
          cout<<"1\n";
        }
        else{
           int k = min(v[0].second,v[1].second);
           int ans = k - v[1].first;
           if(v[0].first < v[1].first){
              ans++;
           }
           if(k < max(v[0].second,v[1].second)){
             ans++;
           }
           cout<<ans<<endl;
        }
    }
}