#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1, 1);

        if (n % 2 != 0) {
            stack<int> s;
            s.push(n);
            s.push(n - 1);
            int num = n - 2;

            while (num > 0) {
                s.push(num);
                num -= 2;
            }
            num = 2;
            while (num < n - 1) {
                s.push(num);
                num += 2;
            }

            cout << n << endl;
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        } else {
        
            int num = 1;
            stack<int> s;
            
      
            while ((1 << (num + 1)) <= n) {
                  num++;
            }
            
            if ((1 << num) == n) {
              
                s.push(n);
                n = n-1;
                s.push(n);
                s.push(n - 1);
                int temp = n - 2;

                while (temp > 0) {
                    s.push(temp);
                    temp -= 2;
                }
                temp = 2;
                while (temp < n - 1) {
                    s.push(temp);
                    temp += 2;
                }
            } 
            else {
                int k = 1 << num;
                v[k - 1] = 0;
                s.push(k - 1);
                v[n] = 0;
                v[n - 1] = 0;
                s.push(n - 1);
                s.push(n);

                for (int i = 1; i <= n; i++) {
                    if (v[i] == 1) {
                        s.push(i);
                    }
                }
            }

            cout << ((2 << num) - 1) << endl;
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        cout << endl;
    }
    
    return 0;
}
