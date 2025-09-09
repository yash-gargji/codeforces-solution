#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        map<int,int>mp;
        mp[0] = n;
        int num = 0;
        vector<int>pre(n,n);

        for(int i = 0;i<n;i++){
           cin>>a[i];
        }
        for(int i = 0;i<n;i++){
           cin>>b[i];
        }
        int fl = 1;
        if(a[n-1] != b[n-1]){
            cout<<"NO\n";
            continue;
        }

        for(int i = n-1;i >= 0;i--){
            num = num ^ a[i];
            if(i == n-1 || a[i] == b[i]){
               pre[i] = i + 1;
               mp[num] = i;
               continue;
            }
            if((a[i] ^ a[i+1]) == b[i]){
               pre[i] = i + 2;
               mp[num] = i;
               continue;
            }
            if(mp.count(num ^ b[i]) && pre[i + 1] == mp[num ^ b[i]]){
               pre[i] = pre[i+1];
            }
            else {
                fl = 0;
            }
             mp[num] = i;
            
        }
        if(fl){
             cout<<"YES\n";
        }
        else {
          cout<<"NO\n";
        }
    }
}