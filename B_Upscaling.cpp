#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int n;
           cin>>n;
            n = 2*n;

            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(i%4 <= 1 ){
                       if(j%4 <= 1){
                        cout<<"#";
                       }
                       else {
                        cout<<".";
                       }
                    }
                    else {
                         if(j%4 <= 1){
                        cout<<".";
                       }
                       else {
                        cout<<"#";
                       }
                    }
                }
               cout<<endl;
            }
      }
          
      }
