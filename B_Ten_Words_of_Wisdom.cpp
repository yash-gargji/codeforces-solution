#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         int ans = 0;
         int count = -1;
         for(int i = 0;i<n;i++){
            int num,k;
            cin>>num>>k;
               if(num <= 10){
                if(k >= ans){
                  ans = k;
                  count = i+1;
                }
               }
         }
         cout<<count<<endl;
         
    }
    
}