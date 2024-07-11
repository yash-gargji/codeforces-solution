#include<bits/stdc++.h>
using namespace std;

int main(){
     long long int n,k;
     cin>>n>>k;
     map<long long,long long>m;
     vector<long long>v;

     for(int i = 0;i<n;i++){
         long long int num;
         cin>>num;
         m[num]++;
     }
     for(auto it:m){
         v.push_back(it.first);
     }
     int l = 0;
     int r = v.size()-1;

     while(l < r && k > 0){
          if(m[v[l]] <= m[v[r]]){
            long long num = v[l+1] - v[l];
            if(num*m[v[l]] <= k){
                m[v[l+1]] += m[v[l]];
                 k -= num*m[v[l]];
                l++;
            }
            else{
                v[l] += k / m[v[l]];
                break;
            }
          }
          else{
             long long num = v[r] - v[r-1];
            if(num*m[v[r]] <= k){
                m[v[r-1]] += m[v[r]];
                 k -= num*m[v[r]];
                r--;
            }
            else{
                v[r] -= k / m[v[r]];
                break;
            }
          }
       
     }
    cout<<v[r] - v[l];
}