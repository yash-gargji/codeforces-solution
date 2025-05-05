#include <bits/stdc++.h>
using namespace std;

const int N = 8e6;
vector<bool> is_prime(N + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    sieve();
    vector<int>p;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i])
           p.push_back(i);
    }
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       int arr[n];
       

       for(int i = 0;i<n;i++){
          cin>>arr[i];
       }

       sort(arr,arr+n);
       int ind = 0;
       long long coins = 0; 
       int ans = 0;

       for(int i = n-1;i >= 0;i--){
          if(arr[i] >= p[ind]){
             coins += arr[i] - p[ind];
             ind++;
             continue;
          }
          else if(p[ind] - arr[i] <= coins){
              coins = coins - p[ind] + arr[i];
              ind++;
          }
          else{
             ans = i + 1;
             break;
          }
       }
       cout<<ans<<endl;
    }
    return 0;
}
