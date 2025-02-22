#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    set<int> s, even;
    s.insert(-1);

    int arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i == 0 || i % 2) {
        if (arr[i] == 0) even.insert(i);
      } else if (i % 2 == 0 && arr[i] == 1) {
        s.insert(i);
      }
    }
    int q;
    cin >> q;

    while (q--) {
      int ind, x;
      cin >> ind >> x;
      ind--;
      if (ind == 0 || ind % 2 == 1) {
        if (x == 0) {
          even.insert(ind);
        } else {
          even.erase(ind);
        }
      } else {
        if (x == 1) {
          s.insert(ind);
        } else {
          s.erase(ind);
        }
      }
      auto it = prev(s.end());
      if (even.lower_bound(*it) == even.end()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }
}