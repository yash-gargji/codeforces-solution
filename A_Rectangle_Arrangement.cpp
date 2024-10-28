#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int prev = -1;
        int count = 0;
        int num = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
           int k;
           cin>>k;
            if(k > prev){
               ans++;
               count = 1;
            }
            else if(k == prev){
                count++;
            }
            num = max(num,count);
        }
        cout<<ans - count<<endl;
    }
}
