#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         vector<int>v(n);

         for(int i = 0;i<n;i++){
             cin>>v[i];
         }
         bool f = false;
         long long int max_pos = 0;
         long long int max_neg = 0;
         

         for(int i = 0;i<n;i++){
             if(f == false){
                max_pos = max_pos + v[i];
                if(max_pos < 0){
                   f = true;  
                   max_neg = max_pos;
                   max_pos = abs(max_pos);
                }
             }
             else{
                 max_neg  += v[i];
                  max_pos = max(abs(max_pos + v[i]),abs(max_neg));   
             }
         }
        cout<<max_pos<<endl;
     }
}