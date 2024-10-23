#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int r;
        cin>>r;
        int ans = 0;

        int o = 0;
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            ans += num - num % 2;
            r-= num/2;
            o += num % 2;
        }
        cout<<ans+min(2*r - o,o)<<endl;
    }
}