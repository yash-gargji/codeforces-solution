#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;

        vector<int>v;
        vector<pair<int,int>>ans;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            v.push_back(num);
        }

        while(1){
           int f = 0;
           vector<int>k;

           for(int i = 0;i<v.size();i++){
               if(v[i] == 0){
                 f = 1;
                 if(i == v.size()-1){
                     ans.push_back({v.size()-1,v.size()});
                    continue;
                 }
                 ans.push_back({i+1,i+2});
                 k.push_back(10);
                 for(int j = i + 2;j<v.size();j++){
                     k.push_back(v[j]);
                 }
                 break;
               }
               k.push_back(v[i]);
           }
           if(f == 1){
              v = k;
           }
           else{
            break;
           }
        }
        ans.push_back({1,v.size()});

        cout<<ans.size()<<endl;

        for(int i = 0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        
    }
}
