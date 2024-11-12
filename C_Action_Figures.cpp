#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
         long long int ans = 0;
         
         string s;
         cin>>s;
         int l = 0;
         int r = n-1;

         while(l <= r){
             if(r - 1 > l && s[r-1] =='0'){
                r = r-1;
                while(r >= l){
                   if(s[r] =='0'){
                      ans += r+1;
                      r--;
                   }
                   else
                    break;
                }
             }
             else if(r == l){
                  ans += r+1;
                  l++;
             }
             else{
                ans += l+1;
                r--;
                l++;
             }
         }
       cout<<ans<<endl;
    }
}