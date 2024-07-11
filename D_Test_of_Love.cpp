#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        
        int prev_log = -1;
        int prev_water = -1;
        int flag = 0;
        int start = 1;
        
        for (int i = 0; i <= n; i++) {

            if (start == 1 || s[i] == 'L') {
                int ind = i + 1;
                if (start == 1) {
                    ind = 0;
                    start = 0;
                } else {
                    ind = i + 1;
                }

                prev_log = -1;
                prev_water = -1;

                for (int j = ind; j < ind + m && j <= n; j++) {
                    if (j == n) {
                        prev_log = n;
                        break;
                    }
                    if (s[j] == 'L') {
                        prev_log = j;
                    } 
                    else if (s[j] == 'W') {
                        prev_water = j;
                    }
                }

                if ( prev_log == n) {
                    flag = 1;
                    break;
                }
                if (prev_log == -1 && prev_water == -1) {
                    break;
                }
                if (prev_log != -1) {
                    i = prev_log - 1;
                    continue;
                } else if (prev_water != -1) {
                    i = prev_water - 1;
                    continue;
                }
            } else {
                int j = i;
                int count = 0;
                while (count < k) {
                    if (j == n || s[j] == 'C') {
                        break;
                    } else if (s[j] == 'L') {
                        break;
                    }
                    count++;
                    j++;
                }
                k = k - count;
                if (s[j] == 'C') {
                    break;
                } else if (j == n) {
                    flag = 1;
                    break;
                } else if (s[j] != 'L' && count == k) {
                    break;
                }
                i = j - 1;
            }
        }

        if (flag == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
