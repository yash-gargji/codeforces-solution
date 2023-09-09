#include<bits/stdc++.h>
using namespace std;

int main(){
       int t;
       cin>>t;
     while(t--){
        int n;
        cin>>n;
        set<int>s;

        int ans = 0;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
              s.insert(arr[i] + arr[j]);
            }
        }
        for(auto &value : s){
              int count = 0;
             int i = 0;
             int j = n-1;
             while(i < j && max(i,j) != n){
                     if(arr[i] + arr[j] == value){
                        count++;
                        i++;
                        j--;
                     }
                     else if(arr[i] + arr[j] > value){
                        j -- ;
                     }
                     else{
                        i++;
                     }
                     ans = max(ans,count);
             }
        }
        cout<<ans<<endl;
     }
}