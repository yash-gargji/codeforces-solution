#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        map<int,vector<int>>mp;
        
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            mp[arr[i] + 1].push_back(i);
        }
        int ans = 0;

        while(mp.size() > 0 ){
             int ind = mp.rbegin()->second.back();
             int mi = mp.begin()->first;
             if(mi + k >= arr[ind]){
                mp.erase(mp.rbegin()->first);
                continue;
             }
             ans += k;
             arr[ind]--;
             int num = mp.rbegin()->first;
             mp[num].pop_back();
             if(mp[num].size() == 0)
                mp.erase(num);
             int end = mp.begin()->second.back();
             mp.begin()->second.pop_back();
             if(mp[mi].size() == 0)
                mp.erase(mi);
             arr[end]++;
             mp[mi + 1].push_back(end);
        }
        
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
            ans += arr[i]*(arr[i] + 1)/2;
        }
      cout<<ans<<endl;
    }
}