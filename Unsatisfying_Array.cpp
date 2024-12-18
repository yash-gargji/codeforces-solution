#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
       int n,k;
       cin>>n>>k;

       vector<int>v(n,1);
       int flag = 1;
       vector<vector<int>>p;
       
       for(int i = 0;i<k;i++){
           int l,r,m;
           cin>>l>>r>>m;
           l--;
           r--;
           p.push_back({l,r,m});
       }
       sort(p.begin(),p.end());
        for(int i = 0;i<k;i++){
           int l,r,m;
           l = p[i][0];
           r = p[i][1];
           m = p[i][2];
           int mi = 1e9;

           for(int j = l;j<= r;j++){
               mi = min(mi,v[j]);
           }
           if(mi == m){
               for(int j = l;j<= r;j++){
                  if(v[j] == mi)
                     v[j]++;
               }
           }
       }

       for(int i = 0;i<k;i++){
           int l,r,m;
           l = p[i][0];
           r = p[i][1];
           m = p[i][2];
           int mi = 1e9;

           for(int j = l;j<= r;j++){
               mi = min(mi,v[j]);
           }
           if(mi == m || mi > n){
               flag = 0;
           }
       }
       if(flag == 0){
          cout<<"-1\n";
       }
       else{
         for(int i = 0;i<n;i++){
           cout<<v[i]<<" ";
         }
         cout<<endl;
       }
    }
}