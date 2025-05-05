#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int a[n];
         int b[n];
         map<int,int>mb;

         for(int i = 0;i<n;i++){
            cin>>a[i];
         }
         int count = 0;
         for(int i = 0;i<n;i++){
            cin>>b[i];
            mb[b[i]] = i;
            if(a[i] == b[i])
              count++;
         }
         if(count > 1){
             cout<<"-1\n";
             continue;
         }
         vector<pair<int,int>>v;
         if(count == 1){
            for(int i = 0;i<n;i++){
                if(a[i] == b[i] ){
                    swap(a[i],a[(n+1)/2-1]);
                    swap(b[i],b[(n+1)/2-1]);
                    mb[b[i]] = i;
                    mb[b[(n+1)/2-1]] = (n+1)/2-1;
                    if(i != (n+1)/2-1)
                      v.push_back({i+1,(n+1)/2});
                }
             }  
         }
         int ind = 0;

         while(v.size() <= n && ind < n){
              int s = mb[a[ind]];
              if(ind == n - s - 1){
                 ind++;
                 continue;
              }
              int sw = n - ind - 1;
              mb[b[s]] = sw;
              mb[b[n-ind-1]] = s;
              swap(a[sw],a[s]);
              swap(b[s],b[sw]);
              v.push_back({s+1,sw+1});
         }
         int flag = 1;
         for(int i = 0;i<n;i++){
             if(a[i] != b[n-i-1])
               flag = 0;
         }
         if(v.size() > n || flag == 0){
           cout<<"-1\n";
         }
         else{
           cout<<v.size()<<endl;

           for(int i = 0;i<v.size();i++){
               cout<<v[i].first<<" "<<v[i].second<<endl;
           }
         }
    }
}