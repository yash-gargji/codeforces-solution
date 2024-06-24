#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;

        map<ll, vector<ll>> m;

        for (int i = 0; i < n; i++) { 
            ll num;
            cin >> num;
            m[num % k].push_back(num);
        }

        int count = 0;
        for (auto &it : m) {
            sort(it.second.begin(), it.second.end());
            if (it.second.size() % 2 == 1) {
                count++;
            }
        }

        if ((count > 0 && n % 2 == 0) || (n % 2 && count > 1)) {
            cout << "-1\n";
            continue;
        }

        for (auto it : m) {
            vector<ll>& v = it.second;

            if (v.size() % 2 == 0) {
                for (size_t i = 0; i < v.size(); i += 2) {
                    ans += (v[i + 1] - v[i]) / k;
                }
            } else {
                vector<ll> front(v.size()), rear(v.size());

                for (size_t i = 0; i < v.size() - 1; i += 2) {
                    front[i + 1] = (v[i + 1] - v[i]) / k;
                    if (i > 1) {
                        front[i + 1] += front[i - 1];
                    }
                }

                for (size_t i = v.size() - 1; i > 0; i -= 2) {
                    rear[i - 1] = (v[i] - v[i - 1]) / k;
                    if (i < v.size() - 1) {
                        rear[i - 1] += rear[i + 1];
                    }
                }

                ll num = LLONG_MAX;

                for (size_t i = 0; i < v.size(); i++) {
                    ll p = 0;
                    if (i % 2 == 0) {
                        if (i < v.size() - 1) {
                            p += rear[i + 1];
                        }
                        if (i > 0) {
                            p += front[i - 1];
                        }
                    } else {
                        p += (v[i + 1] - v[i - 1]) / k;

                        if (i > 2) {
                            p += front[i - 2];
                        }
                        if (i < v.size() - 2) {
                            p += rear[i + 2];
                        }
                    }
                    num = min(num, p);
                }
                ans += num;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
