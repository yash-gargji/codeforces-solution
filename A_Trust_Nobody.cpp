#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
        int a;
        cin>>a;
      int arr[a];
      map<int,int>m;
      for(int i = 0;i<a;i++){
        cin>>arr[i];
        m[arr[i]]++;
      }
      if(a == 1){
         if(arr[0]){
            cout<<"-1\n";
            continue;
         }
         else{
            cout<<"0\n";
            continue;
         }
      }
      sort(arr,arr+a);
      if(*min_element(arr,arr+a) == a ){
         cout<<"-1\n";
            continue;
      }
      auto it = m.rbegin();
      int p = it->first;
      int count = 0 ;
      if(p == a){
        if(it->second == a){
            cout<<"-1\n";
            continue;
        }
         count = count + it->second;
      }
      else{
        cout<<arr[0]<<endl;
        continue;
      }
      p = it->second;
      for(int i = 0;i<a;i++){
          if(arr[i] < p){
            count = count + 1;
          }
      }
      cout<<count<<endl;
     }
}
