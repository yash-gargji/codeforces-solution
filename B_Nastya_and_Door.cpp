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
        int count = 0 ;
        int ans = 0;
        int p = 0,l = 1,r = 1; 
        for(int i = 1;i<n-1;i++){
            if(arr[i] >= arr[i+1] && arr[i-1] <= arr[i]){
                 if(count == 0 ){
                    p = i-1;
                    count++;
                 }
                 else{ 
                    if( i - p <= k-2){
                    count++;
                 }
                 else{
                    count = 0;
                 }
                 }
                 if(count > ans){
                    r = i+2;
                    ans = count;
                    l = p+1;
                 }
                 
            }
        }
        l = l - (k-1 - (r-l));
        l = max(1,l);
        cout<<ans+1<<" "<<min(l,n+1-k)<<endl;
    }
    return 0;
}