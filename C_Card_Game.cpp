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

       vector<int>a,b;

       for(int i = 0;i<n;i++){
          if(s[i] == 'A'){
             a.push_back(i+1);
          }
          else{
            b.push_back(i+1);
          }
       }
       int ans = 0;

       if((b[b.size()-1] == n && b.size() > 1 ) || (b[b.size()-1] == n-1 && b[0] == 1 )){
           cout<<"Bob\n";
       }
       else{
           cout<<"Alice\n";
       }


       
    }
}