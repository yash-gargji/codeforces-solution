#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
         string s;
         cin>>s;
         long long int ans = 0;
         int mod = 1e9 + 7;
         map<long long ,long long>m;
         m[0] = 1;
         int one = 0;
         int zero = 0;

         for(int i = 0;i<s.size();i++){
             if(s[i] == '1'){
                 one++;
             }
             else{
                 zero++;
             }
             if(m.find(one - zero) != m.end()){ 
                ans += (m[one - zero] * (s.size() - i)) % mod;
                ans = ans % mod;
             }
             m[one - zero] += i + 2;
         }
        cout<<ans<<endl;
    }
    return 0;
}
