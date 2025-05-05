#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;
         vector<int>v;

         if(k % 2 == 1){
           v.resize(n,n);
           v[n-1] = n-1;
         }
         else{
            v.resize(n,n-1);
            v[n-2] = n;
         }

         for(int i = 0;i<n;i++){
           cout<<v[i]<<" ";
         }

         cout<<endl;
        
    }
}