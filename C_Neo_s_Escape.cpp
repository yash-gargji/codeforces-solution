#include <bits/stdc++.h>
using namespace std;

int main(){   
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        vector<int> vis(n, 0);
        set<pair<int,int>> st;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            st.insert({arr[i], i});
        }
        auto it = prev(st.end());
        vis[it->second] = 1;
        int ans = 1;
        priority_queue<pair<int,int>> pq;
        pq.push(*it);

        while(!pq.empty()) {
            auto itr = prev(st.end());
            auto p = pq.top();
            if (itr->first == p.first) {
                pq.pop();
            } 
            else {
                ans++;
                p = *itr;
                vis[p.second] = 1;
            }
            st.erase(p);

            int ind = p.second;
            if(ind + 1 < n && !vis[ind + 1]){
                vis[ind + 1] = 1;
                pq.push({arr[ind + 1], ind + 1});
            }
            if(ind - 1 >= 0 && !vis[ind - 1]){
                vis[ind - 1] = 1;
                pq.push({arr[ind - 1], ind - 1});
            }
        }

        cout << ans << endl;
    }
    return 0;
}
