#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int>suff(n);
        int count = 0;

        for(int i = n-1;i >= 0;i--){
            if(s[i] == 'A')
              count = 0;
            else if(s[i] == 'C'){
               count++;
            }
            suff[i] = count;
        }
        int ans = 0;

        int a = 0;

        for(int i = 0;i<n;i++){
            if(s[i] == 'C')
              a = 0;
            if(s[i] == 'A')
              a++;
            if(s[i] == 'B'){
               if(a >= suff[i])
                 ans += a;
                else {
                  ans += suff[i];
                  a = 0;
                }
            }
        }
        cout<<ans<<endl;
    }
}