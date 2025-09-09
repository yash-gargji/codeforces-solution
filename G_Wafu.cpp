#include<bits/stdc++.h>
using namespace std;
#define int long long

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int mod = 1e9 + 7;
        int n,k;
        cin>>n>>k;
        unordered_map<int,int>mp;
        set<int>st;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            st.insert(num);
        }
        int ans = 1;

        while(k-- && st.size()){
            int num = *st.begin();
            st.erase(num);
            mp[num]++;
            int a = 0;
            int count = 0;
            while(a < num && k > 0 && num != 1){
                 count = 2*count + 1;
                 a++;
                if(count > k){
                    count = count / 2;
                    k -= count;
                    for(int i = 1;i<a;i++){
                        mp[i] += (1 << (a - i - 1));
                    }
                    if(k != 0){
                       mp[a]++;
                       k--;
                    }
                    count = 0;
                    a = 0;
                }
                else if(a + 1 == num){
                     k -= count;
                    for(int i = 1;i<=a;i++){
                        mp[i] += (1 << (a - i));
                    }
                    break;
                }
            }

        }
        for(auto it:mp){
            ans  = (ans * binpow(it.first,it.second,mod)) % mod;
        }
        cout<<ans<<endl;
    }
}