#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
      while(t--){
          int n;
          cin>>n;
          vector<pair<int,int>>p1,p2,p3;

          for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            p1.push_back({num,i});
          }
          for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            p2.push_back({num,i});
          }
          for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            p3.push_back({num,i});
          }
          sort(p1.begin(),p1.end());
           sort(p2.begin(),p2.end());
           sort(p3.begin(),p3.end());
          
      }
}