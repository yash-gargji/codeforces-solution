#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;  
    vector<long long> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = arr[i] % m;
    }

    map<long long, int> prev1, prev2;
    prev1[0] = 1;

    for(int i = 0; i < n / 2 + n % 2; i++) {
        map<long long, int> curr;
        for (auto it : prev1) {
            curr[it.first] = 1;
            long long sum = (it.first + arr[i]) % m;
            curr[sum] = 1;
        }
        prev1 = curr;
    }

    prev2[0] = 1;
    for (int i = n / 2 + n % 2; i < n; i++) {
        map<long long, int> curr;
        for (auto it : prev2) {
            curr[it.first] = 1;
            long long sum = (it.first + arr[i]) % m;
            curr[sum] = 1;
        }
        prev2 = curr;
    }
    int ans = 0;
    for (auto it : prev1) {
        long long required = m - it.first;
        auto itr = prev2.lower_bound(required);
        
        if (itr != prev2.begin()) {
            --itr;
        }
        
        long long sum = (it.first + itr->first) % m;
        ans = max(ans, int(sum));
    }
    cout << ans << endl;
    return 0;
}
