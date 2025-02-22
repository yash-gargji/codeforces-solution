#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         int ans = 0;
         vector<int>v(n+1);

         for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             v[num]++;
         }
         for(int i = 1;i<=n;i++){
             ans += v[i] % 2;
             v[0] += v[i]/2; 
         }
         if(v[0] > 0 )
           ans++;
        cout<<ans<<endl;
     }
}