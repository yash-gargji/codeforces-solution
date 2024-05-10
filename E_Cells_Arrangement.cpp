#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
          int n;
          cin>>n;
          vector<vector<int>>v;

          for(int i = 1; i<= 1;i++){
             for(int j = 1;j<=n;j++){
                 v.push_back({abs(i - j),i,j});
             }
          }
          sort(v.begin(),v.end());
           cout<<v[0][1]<<" "<<v[0][2]<<endl;
           int count = 1;
          for(int i = 1;i<n*n;i++){
                if(n == count)
                  break;
                if(v[i][0] != v[i-1][0]){
                  cout<<v[i][1]<<" "<<v[i][2]<<endl;
                  count++;
                }
          }
        cout<<endl;
      }

}