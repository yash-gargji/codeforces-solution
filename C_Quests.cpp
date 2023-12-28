#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
      while(t--){
          long long int n,k;
          cin>>n>>k;
           long long int a[n];
           long long int b[n];

           for(int i = 0;i<n;i++){
              cin>>a[i];
           }
           for(int i = 0;i<n;i++){
              cin>>b[i];
           }
           long long int sum = a[0];
             long long int num = a[0];
             long long int ma = b[0];
               long long int ans = a[0];
               ans = num + (k - 1)*ma;

            for(int i = 1;i<min(n,k);i++){
                  num = num + a[i];
                    ma = max(ma,b[i]);
                     ans = max(ans,num + (k - i - 1)*ma);
            }
              
             cout<<ans<<endl;
      }
}