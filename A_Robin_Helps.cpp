#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int sum =  0;
        int ans = 0;

        for(int i = 0;i<n;i++){
           int num;
           cin>>num;
           if(num >= k){
             sum += num;
           }
           if(num == 0 && sum > 0){
              ans++;
              sum--;
           }
        }
       cout<<ans<<endl;
    }
}
