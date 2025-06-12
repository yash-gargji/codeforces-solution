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

        for(int i = 0;i<n;i++){
            if(i < k){
              cout<<"1";
            }
            else{
              cout<<"0";
            }
        }
        cout<<endl;
    }
}