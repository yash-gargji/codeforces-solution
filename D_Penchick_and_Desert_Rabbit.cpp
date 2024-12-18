#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isPerfectSquare(long long n) {
  
    // 0 is considered as a perfect
    // square
    if (n == 0) return true;
    
    long long odd = 1;
    while (n > 0) {
        n -= odd;
        odd += 2;
    }
    return n == 0;
}

int getId (vector <pair <int,int>> &vp, int num) {
    int st = 0, ed = vp.size()-1;
    int ans = -1;
    while (st <= ed) {
        int m = (st+ed)/2;
        if (vp[m].first < num) {
            ans = m;
            ed = m-1;
        }
        else st = m+1;
    }
    return ans;
}

signed main(){
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector <int> v (n);
    for (int i = 0; i<n; i++)
        cin >> v[i];
    
    vector <int> dp (n);
    dp[0] = v[0];
    for (int i = 1; i<n; i++)
        dp[i] = max (dp[i-1], v[i]);

    vector <pair <int,int>> vp;
    vp.push_back({v.back(), dp.back()});
    for (int i = n-2; i>=0; i--) {
        int ind = getId (vp, v[i]);
        if (ind != -1) {
            dp[i] = vp[ind].second;
        }
        if (v[i] < vp.back().first) {
            vp.push_back({v[i], dp[i]});
        }
    }

    for (auto it : dp)
        cout << it << " ";
    cout << "\n";
  }
} 