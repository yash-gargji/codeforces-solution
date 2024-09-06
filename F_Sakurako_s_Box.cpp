 #include<bits/stdc++.h>
using namespace std;
#define int long long
int mod_pow(int x, int y, int mod) {
  int res = 1;
  while (y > 0) {
    if (y % 2) res = (res * x) % mod;
    x = (x * x) % mod;
    y /= 2;
  }
  return res;
}
int mod_inv(int x, int mod) { 
    return mod_pow(x, mod - 2, mod) % mod; 
    }
signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int num = n*(n-1)/2;
        int arr[n];
        int mod = 1e9 + 7;
        long long  ans = 0;
        int sum  = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        for(int i =0;i< n;i++){
            sum = (sum - arr[i] + mod) % mod;
            int num = (sum * arr[i] ) % mod;
            ans += num;
            ans = (ans + mod) % mod;
        }
        ans = ans * mod_inv(num % mod, mod) % mod;
       cout<<ans<<endl;
    }
}