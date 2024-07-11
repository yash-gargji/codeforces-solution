#include<bits/stdc++.h>
using namespace std;
 
int main(){
   int k,n;
   cin>>k>>n;
   map<string,vector<int>>m;
   map<string,int>flag;

   for(int i = 0;i<k;i++){
      string s;
      cin>>s;
      int num;
      cin>>num;
      m[s].push_back(num);
   }
   long long int ans = 0;
   int extra = 0;
   for(auto &it:m){
      sort(it.second.begin(),it.second.end());
   }
   for(auto &it:m){
     if(flag.find(it.first) != flag.end()){
        continue;
     }
     string st(it.first.size(),' ');
     int ind = 0;
     for(int i = it.first.size()-1;i >= 0;i--){
        st[ind++] = it.first[i];
     }
     flag[it.first] = 1;
     flag[st] = 1;
     if(it.first == st){
       auto &v = it.second;
       for(int i = v.size()-1;i >= 0;i -= 2){
           if(v[i] <= 0){
              break;
           }
           if(i == 0){
              if(v[i] >= 0){
                extra = max(extra,v[i]);
              }
           }
           else{
              if(v[i] + v[i-1] >= 0){
                 ans += v[i] + v[i-1];
                 if(v[i-1] <= 0){
                     extra = max(extra,abs(v[i-1]));
                 }
              }
              else {
                 extra = max(extra,v[i]);
              }
           }
       }
     }
     else{
        auto &v1 = it.second;
        auto &v2 = m[st];
        int i1 = v1.size()-1;
        int i2 = v2.size()-1;

        while(i1 >= 0 && i2 >= 0){
            if(v1[i1] + v2[i2] >= 0){
               ans += v1[i1] + v2[i2];
               i1--;
               i2--;
            }
            else
              break;
        }
     }
   }
   cout<<ans + extra;
}