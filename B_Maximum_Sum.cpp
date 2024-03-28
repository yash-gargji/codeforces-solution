#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll max_subarray_sum(const vector<ll>&arr) {
    ll max_ending_here = arr[0];
    ll max_so_far = arr[0];
    
    for (size_t i = 1; i < arr.size(); ++i) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int main(){
    int t;
    cin>>t;
    while(t--){
         ll n,k;
         cin>>n>>k;
         vector<ll>arr(n);  
        long long int mod = 1e9+7;
        long long int sum = 0;

        for(int i = 0;i<n;i++){
           cin>>arr[i];
           sum += arr[i];
           sum = (sum % mod + mod) % mod; 
        }
        ll num = max_subarray_sum(arr);
        if(num <= 0)
        {
            cout<<sum<<endl;
            continue;
        }
        num = num%mod;
        sum += num;
        sum = (sum % mod + mod) % mod; 
        k--;
        while(k-- ){
             num = num*2;
             num = num%mod;
             sum += num;
             sum = (sum % mod + mod) % mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
