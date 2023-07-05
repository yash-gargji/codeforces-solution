#include<bits/stdc++.h>
using namespace std;

int main(){
       int t;
       cin>>t;
       while(t--){
           int n;
           cin>>n;
           map<int,vector<int>>m;
           
           for(int i = 0;i<n;i++){
                 int num;
                 cin>>num;
                 m[num].push_back(i);
           }
           pair<int,pair<int,int>>p[m.size()];
             int min  = n;
           int max = -1;
           int i = 0;
            for(auto value:m){
              auto num  = value.first;
              auto v = value.second;
              if(v.size() == 1){
                 p[i].first  = 0;
                 i++;
                 continue;
              }
              p[i] =  {v[v.size() - 1] - v[0] + 1,{v[0] , v[v.size() - 1] }};
              i++;
            }
            n = m.size();
            int count  = 0;
           sort(p,p+n);
             count  = count + p[n-1].first;
             max = p[n-1].second.second;
             min = p[n-1].second.first;

           for(int i = n -2;i>= 0;i--){
               auto value  = p[i].second;
               if(p[i].first == 0){
                continue;
               }
               if(value.first >=max){
                  max = value.second;
                  count = count + p[i].first;;
               }
                 else if(value.second <= min){
                  min = value.first;
                  count = count + p[i].first;
               }
            //    else if((value.second <= max && value.second >= min) && value.first <= min){
            //     count  = count + min  - value.first;
            //     min = value.first;
            //    }
            //     else if((value.first <= max && value.first >= min) && value.second > max){
            //     count  = count  -  max  +value.second;
            //     max = value.second;
            //    } 
           } 
           cout<<count<<endl;
       }
    return 0;
}