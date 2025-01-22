#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k,l;
        cin>>n>>k>>l;
        
        int time = 0;
        int pos = 0;
        int prev = 0;
        
        int arr[n];

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            arr[i] = 2*arr[i];
        }
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            if(arr[i] > pos){
               time += arr[i] - pos;
               arr[i] = pos;
               prev += arr[i] - pos;
               pos += 2*k;
               i--;
            }
            else {
               if(arr[i] + time - prev >= pos - k){
                  pos = min(arr[i] + time - prev,pos) + 2*k;
               }
               prev = 0;
            }
        }
        if(pos < 2*l){
           time += 2*l - 2*k - (arr[n-1] + time - prev);
        }
       cout<<time<<endl;
    }
}