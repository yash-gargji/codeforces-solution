#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        string  s;
        cin>>s;
          int i = n - 1;
          while(i > 0){
            if(i-2 <= 0 || s[i-2] == ')' ){
                ans++;
                i = i-2;
            }
            else{
               ans += 4;
               i -= 4;
            }
         }
        cout<<ans<<endl;
    }
}