#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
      if(a.size() != b.size()){
        cout<<'"-1\n';
        return 0;
      }
    for(int i = 0;i<a.size();i++){
          if(b[i] > a[i]){
            cout<<"-1\n";
            return 0;
          }
        
    }
  cout<<b;
}