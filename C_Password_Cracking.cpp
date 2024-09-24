#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int n;
           cin>>n;
            int front = 1;
                string s;
                
            while(s.size() != n){
                int num;
                if(front == 1){
                   string k = s + '0';
                   cout<<"? "<<k<<endl;
                   cin>>num; 
                   if(num == 1){
                      s = k;
                      continue;
                   }
                }
                if(front == 1){
                   string k = s + '1';
                   cout<<"? "<<k<<endl;
                   cin>>num; 
                   if(num == 1){
                      s = k;
                      continue;
                   }
                }
                front = 0;
                string k = '0' + s;
                cout<<"? "<<k<<endl;
                cin>>num;
                if(num){
                   s = k;
                }
                else {
                     s = '1' + s;
                }
            }
        cout<<"! "<<s<<endl;  
      }
}