#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string p = s;
        reverse(p.begin(),p.end());
        
        if(p<=s && k==0){
         cout<<"NO\n";
         continue;
        }
        int fl = 0;
        for(int i=0;i<n-1;i++){
         if(p[i]!=p[i+1])
           fl=1;
        }
        if(fl ==0){
         cout<<"NO\n";
          continue;
        }
        
        cout<<"YES\n";
    }
}
