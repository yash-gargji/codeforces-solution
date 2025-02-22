#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;

       int ans = INT_MAX;
      vector<int> add = {999999999,99999999,9999999,999999,99999,9999,999,99,9};

       for(int i = 0;i<add.size();i++){
           int num = n;

            int count = 0;
            while(count < 10){
                string s = to_string(num);
                for(int j = 0;j<s.size();j++){
                    if(s[j] == '7')
                       ans = min(ans,count);
                }
                num += add[i];
                count++;
            }
       }
      cout<<ans<<endl;
    }
}