#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin >> n;

        if (n % 2 != 0) {
            int t = n / 2;
            cout << n * t * (t + 1) / 2 - t * (t + 1) * (2 * t + 1) / 6 + t + 1 << endl;
        } else {
            int t = (n - 1) / 2;
            cout << n * t * (t + 1) / 2 - t * (t + 1) * (2 * t + 1) / 6 + t + 1 +
                        (n / 2) * (n / 2) + 1;
            cout << endl;
        }
    }
}