#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        n = 2*n;
        vector<int>v(n),ans(n);

        for(int i = 0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int l = 0;
        int r = n-1;
        long long sum = 0;
        int ind = 0;

        for(int i = 0;i<n/2;i++){
           sum += v[r] - v[l];
           ans[ind++] = v[r];
           ans[ind++] = v[l];
           r--;
           l++;
        }
       cout<<sum<<" ";

      for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
      }
      cout<<endl;
    }
}
