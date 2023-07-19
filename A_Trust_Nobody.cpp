#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
        int a;
        cin>>a;
      int arr[a];
      map<int,int>m;
      for(int i = 0;i<a;i++){
        cin>>arr[i];
        m[arr[i]]++;
      }
          int count = 0 ;
          for(auto it  = m.rbegin() ;it != m.rend() ; it++){
                  int x = it->first;
                  if(x == count){
                     continue;
                  }
                  else{
                        int num = a - x;
                           if(it->second - num >=0) {
                               count += it->second - num ;
                           }
                  }
          }
       
      cout<<count<<endl;
     }
}
