#include<bits/stdc++.h>
using namespace std;

int main(){
         int t;
         cin>>t;
         while(t--){
             int n;
             cin>>n;
               map<int,int>m;                 
              long long int y = 0;
                for(int i = 0;i < n ; i++){
                      int num;
                      cin>>num;        
                     
                        m[num]++;
                        y  = y + num -1;
                }
               
                 if(n == 1){
                    cout<<"NO\n";
                    continue;
                 }
                int max = 0;
                int ans;
                    
                for(auto value : m){
                      if(value.second > max){
                        max = value.second;
                        ans = value.first;
                      }
                }
               
                if( max >= n/2 + n%2 && ans == 1 ) {
                   
                    if(  y < max){
                        cout<<"NO\n";
                        
                    }
                    else{
                        cout<<"YES\n";
                    }
                }     
                  else{
                        cout<<"YES\n";
                    }    
         }
}