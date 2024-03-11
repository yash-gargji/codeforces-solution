#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long int n;
        cin >> n;
        long long int ans = 1e9;
        
        for(int i = 0; i <= 30; i++) {
            for(int j = 0; j <= 10; j++) {
                for(int k = 0; k <= 5; k++) {
                    for(int l = 0; l <= 3; l++) {
                        long long int s = i + j*3 + k*6 + l*10;
                        if(s <= n && (n-s) % 15 == 0) {
                            ans = min(ans, (n-s)/15 + i + l + k + j);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
