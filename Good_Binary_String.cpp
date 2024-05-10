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
            vector<int> a;
    
            for(int i = 1; i < n; i += 2){
                 if(s[i] != s[i-1]){
                      if(a.empty()){
                          a.push_back(i+1);
                      }
                      else{
                          int size = a.size();
                          size--;
                          if(s[a[size] - 1] != s[i]){
                             a.push_back(i+1);
                          }
                          else{
                              a.push_back(i);
                          }
                      }
                 }
            }
          if(a.size() == 1){
               cout<<1<<endl<<a[0]<<endl;
          }
        //   else if((a.size())%2 == 1){
        //        cout<<"-1\n";
        //   }
          else{
              cout<<(a.size())<<endl;
              for(int i = 0;i<a.size();i++){
                  cout<<a[i]<<" ";
              }
              cout<<endl;
          }
     }
     return 0;
}
