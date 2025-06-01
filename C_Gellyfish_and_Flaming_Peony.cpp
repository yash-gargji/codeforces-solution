#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int gcd = 0;
        map<int,int>d,vis;
        queue<int>q;

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            gcd = __gcd(arr[i],gcd);
            if(vis.count(arr[i]))
              continue;
            d[arr[i]] = 0;
            vis[arr[i]] = 1;
            q.push(arr[i]);
        }
        sort(arr.begin(),arr.end());
        if(gcd == arr[0]){
           auto it = upper_bound(arr.begin(),arr.end(),gcd) - arr.begin();
           cout<<n - it<<endl;
           continue;
        }
        int ans = 0;

        while(!q.empty()){
            auto val = q.front();
            q.pop();

            if(val == gcd){
               ans = d[val];
               break;
            }
            for (auto it : arr) {
            int num = __gcd(val, it);
            if (vis.count(num) == 0) {
                vis[num] = 0;
                d[num] = d[val] + 1;
                q.push(num);
            }
            }
        }
        cout<<ans + n-1<<endl;
    }
}