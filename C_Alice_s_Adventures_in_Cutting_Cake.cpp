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
  int n = 100;
  for (int i = 0; i<n; i++) {
    for (int j = i+1; j<n; j++) {
      for (int k = j+1; k<n; k++) {
        if (isPerfectSquare(j-i) && isPerfectSquare (k-i) && isPerfectSquare (k - j)) {
          cout << i << " " << j << " " << k << "\n";
        }
      }
    }
  }
} 