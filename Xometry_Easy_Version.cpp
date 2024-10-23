#include<bits/stdc++.h>
using namespace std;

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        vector<int>m(1 << 20);
        
        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int num = arr[i] ^ arr[j];
                m[num]++;
            }
        }
        long long ans = 0;

        for(auto &it:m){
            int k = it;
            if(k > 1)
            ans += 4*(k - 1) * k;
        }
       cout<<ans<<endl;
    }
}