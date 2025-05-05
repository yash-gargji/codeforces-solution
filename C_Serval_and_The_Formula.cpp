#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if(a == b){
            cout<<"-1\n";
            continue;
        }
        if((a + b) == (a ^ b)){
            cout<<0<<endl;
            continue;
        }
        int p= max(log2(a),log2(b));
        if((1ll << p) != max(a,b))
            p++;
        int ans = (1ll << p) - max(a,b);
        cout<<ans<<endl;
        
    }
}
