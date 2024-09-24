#include<bits/stdc++.h>
using namespace std;

int  main(){
      long long t;
      cin>>t;
      
      while(t--){
           long long n;
           cin>>n;
           long long arr[n];

           for(long long i = 0;i<n;i++){
             cin>>arr[i];
           }
           
           vector<vector<long long >>v;

           for(long long i = 0;i<n;i++){
              long long count = 1;
               long long sum = arr[i];

               for(long long j = i+1;j < n;j++){
                  if(arr[j] <=  arr[j-1]){
                      sum += arr[j];
                      i = j;
                      count++;
                  }
                  else{
                     break;
                  }
               }
              v.push_back({sum,count,sum / count  + (sum % count ? 1 : 0)});
              while(v.size() >= 2 && v[v.size() - 1][2] <= v[v.size() - 2][2]){
                   long long num = v[v.size() - 1][0] + v[v.size() - 2][0];
                   count = v[v.size() - 1][1] + v[v.size() - 2][1];
                   v.pop_back();
                   v.pop_back();
                   v.push_back({num,count,num / count  + (num % count ? 1 : 0)});
              }
            }
          long long mi = 1e10;
          long long ma =  -1e9;

          for(long long i  =0;i<v.size();i++){
            long long a = v[i][2];
            long long b = v[i][0] / v[i][1];
            mi = min({mi,a,b});
            ma = max({ma,a,b});
          }
          cout<<ma-mi<<endl;
      }
}