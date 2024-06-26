// Author :- Tushar
// Date:- 2024-06-25
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define letsgooooooooooo            \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define test         \
  int Tushars_07;    \
  cin >> Tushars_07; \
  while (Tushars_07--)
#define endl "\n"
#define no cout << "NO \n";
#define yes cout << "YES \n";
// const ll mod = 1000000007;
// const ll mod = 998244353;

int32_t main() {
  letsgooooooooooo cout << fixed << setprecision(7);
  test {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int sum = 0;
    int last = 0;
    int out = 0;

    int i = 0;
    while (i < n) {
      sum += arr[i];
      if (sum >= l && sum <= r) {
        out++;
        sum = 0;
        last = i + 1;
      }
      if (sum > r) {
        for (; last <= i && sum > r; last++) {
           sum -= arr[last];
                 out++;
          sum = 0;
          last = i + 1;
        if (sum <= r) {
        }
        }
      }
      i++;
    }
    cout << out << endl;
  }
  return 0;
}