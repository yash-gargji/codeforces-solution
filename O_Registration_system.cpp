#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
     
       map<string,int>m;
       auto it  = m.begin();
       for(int i = 0;i<a;i++){
          string s;
          cin>>s;
              
               if(m[s] == 0 ){
                cout<<"OK\n";
               } 
               else{
                cout<<s<<m[s]<<endl;
               }
                m[s] = m[s] +1;
               
       }    
       return 0;
    }