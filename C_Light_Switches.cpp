#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        vector<int>o,e;

        for(int i = 0;i<n;i++){
         cin>>arr[i];
        }
        int num = *max_element(arr,arr+n);
       for(int i = 0;i<n;i++){ 
           int mod = k - (num - arr[i])%k;
           if(((num - arr[i])/k) % 2){
              o.push_back(mod);
           }
           else{
             e.push_back(mod);
           }
       }
       if(o.size() == 0){
         cout<<num<<endl;
         continue;
       }
        
       if(*min_element(e.begin(),e.end()) > *max_element(o.begin(),o.end())){
          cout<<num + *max_element(o.begin(),o.end())<<endl;
       }
       else if(*min_element(o.begin(),o.end()) > *max_element(e.begin(),e.end())){
          cout<<num + *max_element(e.begin(),e.end())  + k<<endl;
       }
       else{
          cout<<"-1\n";
       }
    }
}