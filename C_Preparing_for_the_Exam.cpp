#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int arr[m];
        int q[k];
        map<int,int>mp;
        
        for(int i = 0;i<m;i++){
           cin>>arr[i];
        }
        for(int i = 0;i<k;i++){
            int num;
            cin>>num;
            mp[num] = 1;
        }
        string s(m,'0');
        string o(m,'1');
        
        if(k >= n){
           cout<<o<<endl;
        }
        else if(k < n-1){
          cout<<s<<endl;
        }
        else {
           for(int i = 0;i<m;i++){
             if(mp.count(arr[i]) == 0){
                cout<<"1";
             }
             else{
                cout<<"0";
             }
           }
          cout<<endl;
        }
    }
}