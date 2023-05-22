#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;
    cin>>a;
    long long int arr1[a],arr2[a];

    for(int i = 0;i<a;i++){
        cin>>arr1[i];
    }
      for(int i = 0;i<a;i++){
        cin>>arr2[i];
    }
     unordered_map<int,int>m;
     vector<int>v;
     int z = 0;
     for(int i = 0;i<a;i++){
      if(arr1[i] - arr2[i] == 0){
        z++;
      }
      else if(arr1[i] - arr2[i] > 0){
            v.push_back(arr1[i] - arr2[i]);
      }
      else{
        m[arr1[i] - arr2[i]]++;
      }
     }
     sort(v.begin(),v.end());
     long long int count =  z*v.size();
     auto it = m.begin();
     for(it = m.begin(); it != m.end();it++){
        int num = it->first;
        num = -(num);
        auto itr = upper_bound(v.begin(),v.end(),num);
        if(itr == v.end()){
            continue;
        }
        else{
          int size =  itr - v.begin();
          size = v.size() - size;
          count = count + size*(it->second);
        }
     }
     count = count + (v.size()*(v.size()-1))/2;
     cout<<count;
    return 0;
}