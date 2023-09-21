#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      int arr[n];
      for(int i = 0;i<n;i++){
           cin>>arr[i];
      }
      string s1,s2;
      cin>>s1>>s2;
      long long int sum = 0;
        vector<pair<long long int ,long long int>>p;
      for(int i = 0;i<n;i++){
              if(s1[i] == s2[i]){
                if( s1[i] == '1'){
                     sum += arr[i];
              }
             }
             else{
                 p.push_back({arr[i],s1[i] - 48});
             }
      }

      long longint flag = n;
      long long ans = p.size()*sum;
      sort(p.begin(),p.end());
      long long int one = 0;

      for(int i = p.size() - 1; i >= 0;i--){
           if(p[i].second == 1){
                flag = i;
                one += p[i].first;
           }
      }
      for(int i = p.size() - 1;i>= flag ;i--){
                one -= p[i].first;
                ans += one;
      }
      long long int z = 0;
      for(int i = 0;i<flag ;i++){
              z += p[i].first;
              ans = ans + z;
      }
      cout<<ans;
      return 0;
} 