#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;
       cout<<n<<" "<<n<<" ";
       for(int i = 2;i<n-2;i++){
           cout<<i<<" ";
       }
       cout<<n<<" "<<2<<endl;
    }
}