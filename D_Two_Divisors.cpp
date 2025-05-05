#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
vector<int> p(N + 1, -1);

void sieve() {
    p[0] = p[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (p[i] == -1) {
            p[i] = i;
            if (1ll*i * i <= N) {
                for (int j = i * i; j <= N; j += i) {
                    if (p[j] == -1)
                        p[j] = i;
                }
            }
        }
    }
}

signed main() {
    sieve();
    int n;
    cin >> n;
    vector<int> a, b;

    for (int i = 0; i < n; i++) {
        map<int, int> mp;
        int num;
        cin >> num;
        int temp = num;
        vector<int>v;

        while(num != 1){
            mp[p[num]]++;
            num /= p[num];
        }
        for(auto it:mp){
            v.push_back(it.first);
        }
        
        if(v.size() < 2){
           a.push_back(-1);
           b.push_back(-1);
           continue;
        }
        a.push_back(v[0]);

        for(int j = 1;j<v.size();j++){
            num *= v[j];
        }
        b.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
}
