#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n;
         int arr[n];
         vector<int>rank(n);
         map<int,int>m;
         for(int i = 0;i<n;i++){
           cin>>arr[i];
           m[arr[i]] = i;
         }
         
         sort(arr,arr + n);
         
         for(int i = 0;i<n;i++){
            rank[m[arr[i]]] = i;
         }
         int ans = 1;
         
         for(int i = 1;i<n;i++){
             if(abs(rank[i] - rank[i-1]) > 1){
                 ans++;
             }
         }
        cout<<ans<<endl;
    }
}