#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n; 
         long long int sum = 0;
         vector<int>v(n+1);

         for(int i = 0;i<=n;i++){
           int num;
           cin>>num;
           v[i] = num;
           sum += num;
         }
         int a = v[n]; 
         sort(v.begin(),v.end());

         for(int i = 0;i<=n;i++ ){
          
             if(v[i] > a && v[i]<= 2*a){
                a = v[i];
             }
         }
        cout<<sum - a<<endl;
    }
}