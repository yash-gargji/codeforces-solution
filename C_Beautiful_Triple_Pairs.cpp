#include <bits/stdc++.h>
using namespace std;

namespace std {
    template <typename T1, typename T2>
    struct hash<pair<T1, T2>> {
        size_t operator()(const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        map<pair<int, int>, long long > k1, k2, k3;
        map<pair<int, int>, map<int, long long>> m1, m2, m3;

        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            k1[{arr[i], arr[i + 1]}]++;
            m1[{arr[i], arr[i + 1]}][arr[i + 2]]++;
            k2[{arr[i], arr[i + 2]}]++;
            m2[{arr[i], arr[i + 2]}][arr[i + 1]]++;
            k3[{arr[i + 2], arr[i + 1]}]++;
            m3[{arr[i + 2], arr[i + 1]}][arr[i]]++;
        }

        for (const auto& it : m1) {
            const auto& m = it.second;
            long long count = k1[it.first];
            for (const auto& p : m) {
                ans += (count - p.second) * p.second;
            }
        }

        for (const auto& it : m2) {
            const auto& m = it.second;
            long long count = k2[it.first];
            for (const auto& p : m) {
                ans += (count - p.second) * p.second;
            }
        }

        for (const auto& it : m3) {
            const auto& m = it.second;
            long long count = k3[it.first];
            for (const auto& p : m) {
                ans += (count - p.second) * p.second;
            }
        }

        cout << ans / 2<< endl;
    }

    return 0;
}
