#include<bits/stdc++.h>
using namespace std;


signed main(){   
     int t;
     cin>>t;

     while (t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        int l = n+1,r = 0;
        int a = 0,b = 0;
        for(int i = 0;i<n;i++){
            cin>>v[i];
        }
        int count = 0;

        for(int i = 0;i<n-1;i++){
           if(v[i] <= k)
             count++;
           else{
               count--;
           }
           if(count >= 0){
              l = min(l,i);
              a++;
              for(int j = i+1;j<min(n-1,i + count + 1);j++){
                    if(v[j] <= k){
                         a++;
                    }
              }
              i += count;
              count = 0;
           }
        }
        count = 0;
        for(int i = n-1;i > 0;i--){
           if(v[i] <= k)
             count++;
           else{
               count--;
           }
           if(count >= 0){
              r = max(r,i);
              b++;
              for(int j = i-1;j > max(0,i - count - 1);j--){
                    if(v[j] <= k){
                         b++;
                    }
              }
              i -= count;
              count = 0;
           }
        }
        
        if(max(a,b) > 1 || l < r){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
     }
     
}