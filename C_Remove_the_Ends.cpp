#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >>n;
        int arr[n];
        vector<int>pre(n),suff(n);
        int ans = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] > 0 )
              pre[i] = arr[i];
             if(i > 0 )
               pre[i] += pre[i-1];
        }
        for(int i = n-1; i >= 0; i--){
            if(arr[i] < 0 )
              suff[i] = -arr[i];
             if(i < n-1 )
               suff[i] += suff[i+1];
            ans = max(ans,pre[i] + suff[i]);
        }
      cout<<ans<<endl;
        
    }

    return 0;
}
