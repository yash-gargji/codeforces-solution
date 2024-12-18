#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
     int n;
     cin>>n;
     int num;
     string s;
     int flag = 0;
     int prev = 0;
     s += '1';

     for(int i = 1;i<n;i++){ 
        cout<<"? 1 "<<i+1<<endl;
         cin>>num;
         if(num > 0 && flag == 0){
            int ind = i-1;
              prev = num;
            while(num--){
              s[ind--] = '0';
            }
            flag = 1;
            s += '1';
         }
         else if(num == 0 && flag == 0){
             s += '1';
         }
         else if(num == prev){
             s += '0';
         }
         else {
            prev = num;
            s += '1';
         }
     }
     if(flag == 1)
      cout<<"! "<<s<<endl;
     else 
      cout<<"! IMPOSSIBLE\n";
  }
}