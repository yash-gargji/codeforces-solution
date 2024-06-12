#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;

   while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> arr(n,vector<char>(m));
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>arr[i][j];
            }
         }

        int ans = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0;j<m;j++) {
                if (arr[i][j] == '#') 
                sum++;
            }
            if (sum > total) {
                total = sum;
                ans = i;
            }
        }
            int start = 0, end = 0;
            int flag = 1;
            for (int i = 0; i <m; i++) {
            if (flag && arr[ans][i] == '#') {
                start = i;
                flag = 0;
            }
            if (arr[ans][i] == '#') {
                end = i;
            }
        }
        std::cout << ans + 1 << " " << (start + end + 2) / 2 << endl;
  }

  return 0;
}