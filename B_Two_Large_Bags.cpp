#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         vector<int>arr(n+2);

         for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             arr[num]++;
         }
         int f = 1;

         for(int i = 1;i<= n;i++){
             if(arr[i] == 1)
                f = 0;
             if(arr[i] > 2){
               arr[i+1] += arr[i] - 2;
             }
         }
         if(arr[n+1] % 2)
           f = 0;
         if(f)
        cout<<"Yes\n";
        else 
         cout<<"No\n";
    }
}