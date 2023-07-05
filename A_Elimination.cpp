#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int n,m;
    cin>>n>>m;
    int k;
     
    cin>>k; 
    if(n*m <= k){
        cout<<0;
        return 0;
    }
     if(n*b <= a){
        cout<<b*(n*m - k);
     }
     else {
        int num = (n*m - k)%n;
        int ans = ((n*m - k)/n)*a;
        if(num*b < a){
               ans += num*b;
        }
        else {
            ans = ans + a;
        }
        cout<<ans;
     }
}