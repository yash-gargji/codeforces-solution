#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
     cin>>t;
     while(t--){
         int x,k;
         cin>>x>>k;
         string s;
         cin>>s;
         vector<int>v;
         v.push_back(0);
         for(int i = 0;i<x;i++){
            if(s[i] == '1'){
                v.push_back(i+1);
            }
         }
         v.push_back(x+1);
         int sum = 0;
         for(int i = 1;i<v.size();i++){
                 int l = v[i] - v[i-1] - 1;
                   if(v[i] != x+1){
                    l = l-k;
                   }
                   if(v[i-1] != 0){
                    l = l-k;
                   }
                   for(int i = 1;i<=l;i = i+k+1){
                          sum++;         
                   }
         }
         cout<<sum<<endl;
     }
     return 0;
}