#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int a,b,x,y;
        cin>>a>>b>>x>>y;

        if(a - b > 1){
            cout<<"-1\n";
        }
        else if(a - b == 1 ){
            if( a % 2 == 1)
              cout<<y<<endl;
            else {
               cout<<-1<<endl;
            }
        }
        else if(a == b){
            cout<<"0\n";
        }
        else {
           int ans = 0;
           while(a < b){
               if(a % 2 == 0){
                  ans += min(x,y);
               }
               else {
                    ans += x;
               }
               a++;
           }
           cout<<ans<<endl;
        }
    }
}