#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
            int n;
            cin>>n;
            vector<int>a(n),b(n+1);
            long long int ans = 0;
            int count = INT_MAX;

           for(int i = 0;i<n;i++){
              cin>>a[i];
           }
           for(int i = 0;i<=n;i++){
              cin>>b[i];
           }
       for(int i = 0;i<n;i++){
          if((a[i] <= b[n] && b[n] <= b[i]) || (a[i] >=  b[n] && b[n] >= b[i]))
             count = 1;
             ans += abs(a[i] - b[i]);
             count = min(count,1 + min(abs(a[i] - b[n]), abs(b[i] - b[n])));
       }
      cout<<ans + count<<endl;
     }
}