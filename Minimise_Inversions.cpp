#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        long long int ans = 0;
        int count = 0;
        int l = 0;
        int r = n-1;

        while(l < r && k > 0){
             if(s[l] == '0'){
                 l++;
                 continue;
             }
             else if(s[r] == '1'){
                  r--;
                  continue;
             }
             s[l] = '0';
             long long int cl = 0,cr = 0;
             int z = 0;
              for(int i = s.size() - 1;i >= 0;i--){ 
                if(s[i] == '0'){
                    z++;
                }
                else 
                cl += count;
            }
            s[l] = '1';
            s[r] = '1';
            z = 0;
            for(int i = s.size() - 1;i >= 0;i--){ 
                if(s[i] == '0'){
                    z++;
                }
                else 
                cr += count;
            }
            s[r] = '0';
            if(cl <= cr){
              s[l] = '0';
              k--;
              l++;
            }
            else{
                s[r] = '1';
                k--;
                r--;
            }
        }

        for(int i = s.size() - 1;i >= 0;i--){ 
            if(s[i] == '0'){
              count++;
            }
            else 
             ans += count;
        }
       cout<<ans<<endl;
    }
}