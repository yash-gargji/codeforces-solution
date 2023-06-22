#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
         int n;
         cin>>n;

          map<int,int>m;
          int count = 0;

          for(int i = 0;i<n;i++){
                  int num;
                  cin>>num;
                  m[num]++;
          }
          int sum = 0;
          for(auto &value:m){
                 int m = value.first;
                 int n = value.second;
                 count = count + n/m;
                 sum = sum + n%m;
                 count = count + sum/m;
                 sum = sum%m;
          }
          cout<<count<<endl;
      }
}