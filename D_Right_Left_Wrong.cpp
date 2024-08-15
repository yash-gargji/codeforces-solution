#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long ans = 0;
        int n;
        cin>>n;

        vector<long long>pre(n);
        
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            pre[i] = num;
            if(i > 0){
               pre[i] += pre[i-1];
            }
        }
        string s;
        cin>>s;
       int l = 0;
       int r = n-1;

       while(l < r){
          if(s[l] == 'R'){
              l++;
              continue;
          }
          else if(s[r] == 'L'){
              r--;
              continue;
          }
         ans += pre[r];
         if(l > 0){
            ans -= pre[l-1];
         }
         l++;
         r--;
       }
      cout<<ans<<endl;
    }

    }    