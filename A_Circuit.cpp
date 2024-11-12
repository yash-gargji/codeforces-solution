#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
      vector<int>v(2*n);

      int one = 0;

      for(int i = 0;i<2*n;i++){
          cin>>v[i];
          if(v[i])
            one++;
      }
      cout<<one % 2<<" ";
       if(one >= n){
          cout<<n - (one - n)<<endl;
       }
       else{
         cout<<one<<endl;
       }
    }
}