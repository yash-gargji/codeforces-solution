#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
     
    while(t--){
        int n, m;
        cin >> n >> m;
         vector<int>prog,test;
        vector<int> a(n + m+1), b(n + m+1);
        long long int ans = 0;

        for (int i = 0; i < n + m + 1; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n + m + 1; i++) {
            cin >> b[i];
        }
        int num = n+m+1;
        int pg = 0;
        int tst = 0;

        for(int i = 0;i<num-1;i++){
             if(pg == n){
                 ans += b[i];
             }
             else if(tst == m){
                 ans += a[i];
             }
             else {
                 if(a[i] >= b[i]){
                    pg++;
                    ans += a[i];
                 }
                 else{
                    tst++;
                    ans += b[i];
                 }
             }
            if(a[i] >= b[i]){
                 prog.push_back(i);
            }
            else
             test.push_back(i);
        }

        pg = 0;
        tst = 0;

        for(int i = 0;i<num-1;i++){
            if(pg == n){
               cout<<ans - b[i] + b[num-1]<<" ";
            }
            else if(tst == m){
                 cout<<ans - a[i] + a[num-1]<<" ";
            }
            else {
                 if(a[i] >= b[i]){
                  long long k = ans - a[i];
                  if(prog.size() >= n+1){
                     k += a[prog[n]] - b[prog[n]] + b[num-1];
                  }
                  else{
                     k += a[num-1];
                  }
                  pg++;
                   cout<<k<<" ";
                 }
                 else{
                     long long k = ans - b[i];
                    if(test.size() >= m+1){
                        k += b[test[m]] - a[test[m]] + a[num-1];
                    }
                    else{
                        k += b[num-1];
                    }
                    tst++;
                     cout<<k<<" ";
                 }
            }
        }
      cout<<ans<<" "<<endl;
    }
}
