#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, b, c;
        cin >> n >> b >> c;

        if (b == 0 && c < n - 2) {
            cout << "-1\n";
            continue;
        } 
        else if (b == 0) {
            if (c > n - 1) {
                cout << n << endl;
            } 
            else {
                cout << n - 1 << endl;
            }
        } 
        else {
            double low = 0;
            double high = n-1;
            int ans = 0;
            while (low <= high) {
                double mid = floor((low + high) / 2.0);
                double val = (mid * b) + c;
                if(val == n){
                    high = mid-1;
                }
                else if (val <= n - 1) {
                    ans = mid +1;
                    low = mid + 1;
                } 
                else {
                    high = mid - 1;
                }
            }
            cout << n - ans << endl;
        }
    }
}
