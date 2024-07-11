#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      int ma = 0;
      vector<int>v[n];
      map<int,int>m;

      for(int i = 0;i<n;i++){
          int num;
          cin>>num;
          ma = max(num,ma);

          for(int j = 1;j*j <= num;j++){
              if(num % j == 1){
                 v[i].push_back(j);
                 if(num/j != j){
                    v[i].push_back(num/j);
                 }
              }
          }
      }
      for(int i = 1;i<=1050;i++){
        
      }
}