#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;
       vector<string>v(n);
       map<int,vector<int>>m;
       map<int,int>k;

       for(int i = 0;i<n;i++){
          cin>>v[i];
          int count = 0;
           for(int j = 0;j<n;j++){
               if(v[i][j] == '1' && j <= i)
                 count++;
           }
          m[count].push_back(i);
          k[i] = count;
       }
       vector<int>vis(n);
       for(auto &it:m){
          auto ve = it.second;
          sort(ve.begin(),ve.end());
          for(int i = ve.size() - 1;i >= 0;i--){
              if(vis[ve[i]] == 1)
                 continue;
                //  cout<<k[0]<<endl;
              for(int j = 0;j < ve[i];j++){
                  if(k[j] == it.first && v[ve[i]][j] == '1'){
                      cout<<j+1<<" ";
                      vis[j] = 1;
                  }
              }
              cout<<ve[i] + 1<<" ";
              vis[ve[i]] = 1;
          }
       }
      cout<<endl;
    }
}