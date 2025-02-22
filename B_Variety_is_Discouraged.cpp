#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>m;
        int ans = 0;
        int l = -1, r = -1;
        
        for(int i  =0;i<n;i++){
           cin>>arr[i];
            m[arr[i]]++;
        }
        int count = 0;

        for(int i = 0;i<n;i++){
             if(m[arr[i]] == 1){
                 count++;
             }
             else{
                 count = 0;
             }
             if(count > ans){
               ans = count;
               l = i - count + 1;
               r = i;
             }
        }
      if(ans == 0){
         cout<<"0\n";
      }
      else{
        cout<<l+1<<" "<<r+1<<endl;
      }
        
    }
}