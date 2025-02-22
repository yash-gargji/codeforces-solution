#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int min_idx = min_element(b.begin(), b.end()) - b.begin();
    vector<int> best_b(m);
    for (int i = 0; i < m; i++) 
        best_b[i] = b[(min_idx + i) % m];
     int f = 0;
    for (int i = 0; i < n-m; i++) {
         if(a[i] > best_b[0]){
            if(m > 1){
               for(int j = i;j<n-m;j++){
                   a[j] = best_b[0];
                   f = 1;
               }
               break;
            }
            else{
               a[i] = best_b[0];
            }
         }
    }
    
        for(int j = 0;j<m;j++){
            if(a[j + n-m] > best_b[j]){
                 f = 1;
                 break;
            }
            else if(a[j+n-m] < best_b[j])
               break;
        }
        if(f){
           for(int i = 0;i<m;i++){
               a[i + n-m] = best_b[i];
           }
        }

    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
