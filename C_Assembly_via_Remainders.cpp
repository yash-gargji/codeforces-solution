#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
          int n;
          cin>>n;
          int k = 1000;

        cout<<k<<" ";

        for(int i = 0;i<n-1;i++){
              int num;
              cin>>num;
              k += num;
              cout<<k<<" ";
        }
        cout<<endl;
      }

}