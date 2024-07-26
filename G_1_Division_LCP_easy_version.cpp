#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
      int t;
      cin>>t;

      while (t--){
          int n,l,r;
          cin>>n>>l>>r;
          string s;
          cin>>s;
          vector<int>z = z_function(s);
          z[0] = n;
          
          int low = 1;
          int high = n / l;
          int ans = 0;

          while(low <= high){
              int mid = (low + high)/2;
              int count = 0;

              for(int i = 0;i<z.size();i++){
                 if(z[i] >= mid){
                     count++;
                     i += mid - 1;
                 }
              }
             if(count >= l){
                 ans = mid;
                 low = mid + 1;
             }
             else{
                high = mid - 1;
             }
          }
        cout<<ans<<endl;
      }
      
}