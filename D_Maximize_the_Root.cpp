// clang-format off
// Author :- Tushar || 30-07-2024 21:16:11
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else 
#define debug(x...) 42
#endif
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed << setprecision(7);
#define endl "\n" 
#define no cout << "NO \n";
#define yes cout << "YES \n";
#define int long long 
#define PI 3.1415926535897932384626433832795
const int inf = 1e9 ,INF = 1e18 ,mod1 = 998244353 ,mod = 1000000007; 
/*
    ∧＿∧
　 (｡･ω･｡)つ━☆・*。
  ⊂/　 /　   ・゜
　しーＪ　　　     °。+ * 。　
　　　　　                .・゜
  */
// clang-format on

void recc(vector<vector<int>> parent, int node, vector<int>& arr, int p) {
  int temp = INF;
  for (auto it : parent[node]){
    if (it != p){
        recc(parent, it, arr, node);
        temp = min(temp, arr[it]);
     }
  }

  if (node == 1) return;

  if (temp != INF && temp > arr[node]) {
    int num = (arr[node] + temp) / 2;
    arr[node] = num;
  } 
  else if (temp < arr[node]) {
    arr[node] = temp;
  }
 return ;
}

int32_t main() {
  fastio;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<int>> parent(n + 1);

    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }

    for (int i = 2; i <= n; i++) {
      int a;
      cin >> a;
      parent[a].push_back(i);
      parent[i].push_back(a);
    }

    int one = 1;
    recc(parent, one, arr, -1);


    int k = INF;
    for (auto it : parent[1]) {
        k = min(k, arr[it]);
    }

    if (k != INF) {
      arr[1] += k;
    }

    cout << arr[1] << "\n";
  }
  return 0;
}