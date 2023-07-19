#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
       int t;
       cin>>t;
       while(t--){
            long long int n,m;
             cin>>n>>m;
             if(m == 1){
                cout<<n*m<<endl;
                continue;
             }
             if(n%10 == 5 ){
                if(m/4 == 0){
                    cout<<n*m<<endl;
                }
                else{
                     cout<<n*(m/4)*4<<endl;
                     continue;
                }
             }
             long long int num = m/5;
             string ans;
             int p = 0;
                while(num > 0){
                    long long int k = n*num*5;
                       string s = to_string(k);
                       int count = 0;
                       for(int i = s.size() - 1;i>= 0;i--){
                        if(s[i] == '0'){
                             count++;
                        }
                        else{
                            break;
                        }
                       }
                      if(count > p){
                          ans = s;
                          p = count;
                      }   
                      num -- ;
                }
                if(p == 0){
                    cout<<n*m<<endl;
                }
                else{
                    cout<<ans<<endl;
                }
       }
}