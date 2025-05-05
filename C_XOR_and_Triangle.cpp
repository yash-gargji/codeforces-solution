#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        if (((n & (n - 1)) == 0) || (((n + 1) & n) == 0)) {
            cout << "-1\n";
        } 
        else {
            int num = (1 << (31 - __builtin_clz(n))) - 1;
            cout << num << endl;
        }
    }
}
