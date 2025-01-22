#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        vector<int>f(21);
        for(int i = 0;i<n;i++){
            cin>>v[i];
            f[v[i]]++;
        }
        int count = 0;
        for(int i = 0;i<= 20;i++){
             if( i!= k && f[i] > f[k]){ 
                 count++;
             }
        }
        if(count == 0){
           cout<<"0\n";
           continue;
        }
        vector<int>num = f;
        int ans = 2;

        for(int i = 0;i<n-1;i++){
            num[v[i]]--;
            int flag = 1;
            for(int j = 0;j<= 20;j++){
                if(num[j] > num[k] && j != k){
                   flag = 0;
                }
            }
            if(flag)
              ans = 1;
        }
        num = f;
        for(int i = n-1;i > 0;i--){
            num[v[i]]--;
            int flag = 1;
            for(int j = 0;j<= 20;j++){
                if(num[j] > num[k] && j != k){
                   flag = 0;
                }
            }
            if(flag)
              ans = 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}