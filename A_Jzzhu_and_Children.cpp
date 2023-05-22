#include<bits/stdc++.h>
using namespace std;

int main(){
   int x,y;
   cin>>x>>y;
   int arr[x];
   vector<pair<int,int>>v;
   for(int i  = 0;i<x;i++){
      cin>>arr[i];
      v.push_back(make_pair(i+1,arr[i]));
   }
   int max = *max_element(arr,arr+x);
   if(max <= y){
    cout<<x;
   }
   else{
    int i = 0;
      while(v.size() != 0){
           if(v.size() == 1){
            cout<<v[0].first;
            break;
           }
           if(v[i].second <= y){
            v.erase(v.begin() +i);
               i = i-1;
           }
           else{
            v[i].second = v[i].second - y;
              v.push_back(make_pair(v[i].first, v[i].second));
              v.erase(v.begin() +i);
               i = i-1;
           }
           i++;
      }
    }
   }
