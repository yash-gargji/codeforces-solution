#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        int x;
        cin>>x;

        int sum = 0;

        for(int i = 0;i<n;i++){
           int num;
           cin>>num;
           sum += num;
        }
        if(sum % x == 0 && sum / n == x){
           cout<<"YES\n";
        }
        else{
           cout<<"NO\n";
        }
        
    }
}