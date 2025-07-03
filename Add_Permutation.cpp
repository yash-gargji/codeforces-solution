#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int k;cin>>k;
        vector<int>v(n);
        set<int>st;
        int sm = 1;

        for(int i = 0;i<n;i++){
            if(i <= n - k){
               cout<<n - i<<" ";
            }
            else{
               cout<<sm++<<" ";
            }
        }
        cout<<endl;
    }
}