#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> vis(n, 0), val(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int start = i, num = i, count = 0;
                stack<int> st;

                while (!vis[num]) {
                    vis[num] = 1;
                    st.push(num);
                    num = arr[num] - 1; 
                    count++;
                }

                pq.push(count);
            }
        }

        int ans = 0;
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a == n && b == n)
              break;
            ans += a + b;
            pq.push(a + b);
        }

        cout << ans << endl;
    }
}
