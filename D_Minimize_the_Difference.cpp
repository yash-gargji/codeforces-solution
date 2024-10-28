#include<bits/stdc++.h>
using namespace std;

int  main(){
      long long t;
      cin>>t;
      
      while(t--){
           long long n;
           cin>>n;
           long long arr[n];
           vector<vector<long long >>v;

           for(long long i = 0;i<n;i++){
             cin>>arr[i];
           }
           for(int i = 0;i<n;i++){
                long long count = 1;
                long long sum = arr[i];

              while(v.size() >= 1 && sum / count <= v[v.size() - 1][2]){
                   sum +=  v[v.size() - 1][0];
                   count += v[v.size() - 1][1];
                   v.pop_back();
              }
              v.push_back({sum,count,sum / count});
          }
          long long mi = 1e18;
          long long ma =  0;

          for(int i = 0;i<v.size();i++){
            long long a = v[i][2];
            long long b = a + (v[i][0] % v[i][1] > 0 ? 1 : 0);
            mi = min({mi,a,b});
            ma = max({ma,a,b});
          }
          cout<<ma-mi<<endl;
      }
}