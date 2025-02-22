#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         int n,k;
         cin>>n>>k;

         int ans = k/2 + 1,prev = 0;
         int arr[n];
         int num = 1;

         for(int i = 0;i<n;i++){
             cin>>arr[i];
             if(prev == 0 && k % 2 == 0){
                 prev++;
                 k--;
                 continue;
             }
             if(num != arr[i] && k % 2){
                 ans = min(ans,num);
             }
             if(n - i == k){
                if(prev >= 2 && k % 2)
                  ans = min(ans,num + 1);
                k--;
                prev = 1;
                if(k % 2 == 0)
                   num++;
                continue;
             }
             else if(k % 2 == 0 && prev >= 2)
               ans = min(ans,num + 1);
             else if(k % 2 && prev >= 3){
                 ans = min(ans,num + 1);
             }
             else if(k % 2 == 0 && arr[i] == num){
                k--;                                        
                prev = 1;
             }
             else{
                prev++;
             }  
         }
        cout<<ans<<endl;
    }
}