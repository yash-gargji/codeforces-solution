#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        
        int a[n], b[m];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        
        sort(a, a+n, greater<int>());
        sort(b, b+m, greater<int>());
        
        int l = 0, r = 0;
        vector<vector<int>> v;
        v.push_back({0,0});
        
        for(int i = 0; i < n+m; i++){
            if(r == m || (l < n && a[l] >= b[r])){
                l++;
            } else {
                r++;
            }
            v.push_back({l,r});
        }
        
        vector<int> pre(n+1), preb(m+1);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i-1];
            pre[i] = sum;
        }
        sum = 0;
        for(int i = 1; i <= m; i++){
            sum += b[i-1];
            preb[i] = sum;
        }

        while(q--){
            int x, y, z;
            cin >> x >> y >> z;
            int num = min({x, z, v[z][0]});
            int num2 = min({m, z - num,y});
            if(num + num2 != z && num <= x){
                num += (z - num - num2);
            }
            if(num + num2 != z && num2 <= y){
                num2 += (z - num - num2);
            }
            cout << pre[num] + preb[num2] << endl;
        }
    }
}
