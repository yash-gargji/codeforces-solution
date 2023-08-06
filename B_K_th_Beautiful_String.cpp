#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
          long long int low = 1;
          long long int high = n;
           long long int ans;
           while(low <= high){
                long long int mid = (high + low)/2;
                if((mid*(mid+1))/2 == k){
                    ans =  mid;
                    break;
                }
                else if((mid*(mid+1))/2 > k){
                    ans = mid;
                   high = mid -1;
                } 
                else{
                    low = mid + 1;
                }
           }
          long long int num = (ans*(ans+1))/2 - k;
           int f = n - ans;
           int r = f + 1 + num;
           for(int i = 1;i <= n;i++){
                if(i == f || i == r){
                    cout<<"b";
                }
                else{
                    cout<<"a";
                }
           }
           cout<<endl;
    }
}