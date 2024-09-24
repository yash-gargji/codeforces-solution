#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
vector<int> spf(MAXN + 1);

void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    sieve();

    int n;
    cin >> n;
    vector<int> arr(n);

    map<int, unordered_set<int>> m;
    vector<int> par(n, -1), dis(n, INT_MAX),adj[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int num = arr[i];
        unordered_set<int> prime_factors;

        while (num != 1) {
            prime_factors.insert(spf[num]);
            num /= spf[num];
        }

        for (int prime : prime_factors) {
            m[prime].insert(i);
            adj[i].push_back(prime);
        }
    }

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "1\n" << a << endl;
        return 0;
    }

    queue<int> q;
    vector<bool> visited(n, false);
    dis[a - 1] = 0;
    q.push(a - 1);
    visited[a - 1] = true;
    map<int,int>vis;

    while (!q.empty()) {
        int ind = q.front();
        q.pop();
        int num = arr[ind];
        for (int prime : adj[ind]) {
             if(vis[prime] == 1)
                continue;
             vis[prime] = 1;
            for (int neighbor : m[prime]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dis[neighbor] = dis[ind] + 1;
                    par[neighbor] = ind;
                    q.push(neighbor);

                    if (neighbor == b - 1) {
                        break;
                    }
                }
            }
        }
    }

    if (dis[b - 1] == INT_MAX) {
        cout << "-1" << endl;
    } else {
        int num = b - 1;
        stack<int> path;
        while (num != -1) {
            path.push(num + 1);
            num = par[num];
        }

        cout << path.size() << endl;
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }

    return 0;
}
