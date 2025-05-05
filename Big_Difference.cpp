#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;

        cin>>n>>k;

        int x = -1, y = -1;

        for(int i = 0;i<=10;i++){
            for(int j = 0;j<10;j++){
                 int a = n-i;
                 int b = n-k-j;

                 if(b <= 0 || abs(a - b) < k || a <= 0){
                    continue;
                 }
                 int prod = a*b;
                 int gcd = __gcd(a,b);
                 if(abs(gcd - prod/gcd) >= 2*k){
                    x = a;
                    y = b;
                 }
                  
            }
        }
      cout<<x<<" "<<y<<endl;
    }
}