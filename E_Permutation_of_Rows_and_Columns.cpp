#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n,m;
          cin>>n>>m;
          map<vector<int>,int>m1,m2;
           vector<vector<int>>r1(n,vector<int>(m)),r2(n,vector<int>(m));
           vector<vector<int>>c1(m,vector<int>(n)),c2(m,vector<int>(n));

           for(int i = 0;i<n;i++){
             for(int j = 0;j<m;j++){
                cin>>r1[i][j];
                c1[j][i] = r1[i][j];
             } 
           }
           for(int i = 0;i<n;i++){
             for(int j = 0;j<m;j++){
                cin>>r2[i][j];
                c2[j][i] = r2[i][j];
             } 
           }
           for(int i = 0;i<n;i++){
               sort(r1[i].begin(),r1[i].end());
               m1[r1[i]]++;
               sort(r2[i].begin(),r2[i].end());
           }
            for(int i = 0;i<m;i++){
               sort(c1[i].begin(),c1[i].end());
               m2[c1[i]]++;
               sort(c2[i].begin(),c2[i].end());
           }
           int flag = 1;

           for(int i = 0;i<n;i++){
                if(m1[r2[i]] == 0){
                      flag = 0;
                      break;
                }
                else
                 m1[r2[i]]--;
           }
              for(int i = 0;i<m;i++){
                if(m2[c2[i]] == 0){
                      flag = 0;
                      break;
                }
                else
                 m2[c2[i]]--;
           }
           if(flag)
             cout<<"YES\n";
            else
              cout<<"NO\n";
           
     }
}