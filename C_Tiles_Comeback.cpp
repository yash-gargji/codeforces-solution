#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
          int n,k;
          cin>>n>>k;
          int arr[n];
          for(int i = 0;i<n;i++){
          cin>>arr[i];
          }
             if(arr[0] == arr[n-1]){
                int count = 2;
                for(int i = 1;i<n-1;i++){
                    if(arr[i] == arr[0]){
                        count++;
                    }
                }
                if(count >= k){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
             }
             else{
                int f = 0,r = n-1;
                   int s1 = 1,s2 = 1;
                      
                   for(int i = 1;i<n-1;i++){
                           if(s1 >= k){
                            break;
                           }
                           if(arr[i] == arr[0]){
                            s1++;
                            f = i;
                           }
                   }
                       
                   for(int i = n-2;i >= 1;i--){
                           if(s2 >= k){
                            break;
                           }
                           if(arr[i] == arr[n-1]){
                            s2++;
                            r = i;
                           }
                   }
                   if((s1 != k || s2 != k) || f >=r){
                           cout<<"NO\n";
                   }
                   else{
                    cout<<"YES\n";
                   }
             }
        }
}