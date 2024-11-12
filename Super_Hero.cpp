#include<bits/stdc++.h>
using namespace std;

int func(int n){
     vector<int>v;

     for(int i = 1;i *i <= n;i++){
         if(n % i == 0){
             v.push_back(i);
             v.push_back(n/i);
         }
     }
     sort(v.begin(),v.end());
     return v[v.size() - 2];
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         long long int n,k;
         cin>>n>>k;
         int ans = 0;
         while(n != 1){
             ans ++;
             n = func(n);
         }
         cout<< ans + floor(log2(k))<<endl;
    }
}