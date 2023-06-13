#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
           int n,m;
           cin>>n>>m;
           int odd = n/2;
           int even = 0;
           for(int i = 1;i<=n;i++){
                  for(int j = 1;j<= m;j++ ){
                    if(i%2 == 1){
                    cout<<odd*m + j<<" ";
                  }
                  else{
                      cout<<even*m + j<<" ";
                  }
                  }
                  if(i%2 == 1){
                       odd++;
                  }
                  else {
                    even++;
                  }
                  cout<<endl;
           }
          
    }
}