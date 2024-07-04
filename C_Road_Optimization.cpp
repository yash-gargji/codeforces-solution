#include <bits/stdc++.h>
using namespace std;

long long dp[501][501];

long long func(int ind, vector<int>& c, vector<int>& speed, int k, int num) {
    if (ind == c.size()-1) {
        return 0;
    }
    if (dp[ind][k] != -1) {
        return dp[ind][k];
    }
    long long take = 1ll * (c[ind + 1] - c[ind]) * speed[ind] + func(ind + 1, c, speed, k, speed[ind]);
    long long not_take = LLONG_MAX;

    if (k != 0) {
        not_take = 1ll * num * (c[ind + 1] - c[ind]) + func(ind + 1, c, speed, k - 1, num);
    }
    return dp[ind][k] = min(take, not_take);
}

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> c(n), speed(n);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    c.push_back(l);
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }
    cout << func(0, c, speed, k, INT_MAX);
}
