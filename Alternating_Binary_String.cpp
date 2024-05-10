#include<bits/stdc++.h>
using namespace std;

int main(){
    
     int t;
     cin>>t;
     while(t--){
           int n;
           cin>>n;
           string s;
           cin>>s;
           int ans =  0;

           for(int i =0;i<n;i++){
                int num = 1;
             for(int j = i+1; j<n;j++){
                   if(s[j] == s[i]){
                      num++;
                      i = j;
                   }
                   else{
                       break;
                   }
             }
              ans += num - 1;
           }
        cout<<ans<<endl;
     }
}