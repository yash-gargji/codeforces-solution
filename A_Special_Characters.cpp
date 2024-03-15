#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
         if(n%2 == 1){
            cout<<"NO\n";
            continue;
         }
        cout<<"YES\n";
         for(int i = 0;i<n/2;i++){
            cout<<"AAB";
         }
         cout<<endl;
    }
}