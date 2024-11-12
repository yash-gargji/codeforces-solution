#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        int a[n],b[n];
        vector<int>v;
        int ans = 0;

        for(int i = 0;i<n;i++){ 
           cin>>a[i];
        }

        for(int i = 0;i<n;i++){ 
           cin>>b[i];
           if(a[i] > b[i]){
              ans++;
           }
           else{
              v.push_back(b[i] - a[i]);
           }
        }
        sort(v.begin(),v.end());
        int bt = 0;
        for(int i = 0;i<v.size();i++){
           if(x > v[i]){
              x -= v[i];
              x--;
              ans++;
           }
           else{
              v[i] -= x;
              x = 0;
              if(v[i] == 0)
                bt++;
           }
        }
        if(ans  > n/2)
          cout<<"YES\n";
        else 
         cout<<"NO\n";
    }
}