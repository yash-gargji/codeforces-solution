#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isPerfectSquare(long long n) {
  
    // 0 is considered as a perfect
    // square
    if (n == 0) return true;
    
    long long odd = 1;
    while (n > 0) {
        n -= odd;
        odd += 2;
    }
    return n == 0;
}

signed main(){
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n%2 == 0) {
      for (int i = 1; i<=n/2; i++)
        cout << i << " " << i << " ";
      cout << "\n";
    }
    else {
      if (n <= 25) cout << "-1\n";
      else {
        vector <int> v (n);
        v[0] = 1;
        v[9] = 1;
        v[25] = 1;
        v[10] = 2;
        v[26] = 2;
        int ct = 3;
        for (int i = 0; i<n; i++) {
          if (v[i] == 0) {
            v[i] = ct;
            v[i+1] = ct;
            ct++;
            i++;
          }
        }
        for (auto it : v)
          cout << it << " ";
        cout << "\n";
      }
    }
  }
} 