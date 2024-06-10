#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         vector<int>v(n);

         for(int i = 0;i<n;i++){
             cin>>v[i];
         }
         int mod =  998244353;

         bool f = false;
         map<long long,long long >m;
         long long int max_pos = 0;
         long long int max_neg = 0;
         m[0] = 1;
         int prev = 0;

         for(int i = 0;i<n;i++){
             if(f == false){
                 if(max_pos + v[i] < 0){
                   f = true;  
                   m[max_pos + v[i]] = m[max_pos]; 
                   m[max_pos] %= mod;
                   max_neg = max_pos;
                   m[abs(max_pos + v[i])] += m[max_pos];
                   m[abs(max_pos + v[i])] %= mod;
                   max_pos = abs(max_pos + v[i]);
                   prev = 1;
                   continue;
                }
                m[max_pos + v[i]] =  (m[max_pos] * 2)% mod;
                max_pos = max_pos + v[i];
                
                
             }
             else{
                    if(v[i] >= 0){
                       m[max_neg + v[i]] += (2*m[max_neg])%mod;
                       m[max_neg + v[i]] %= mod;
                    }
                    else
                      m[max_neg + v[i]] = m[max_neg];
                 max_neg += v[i];

                    if(abs(max_pos + v[i]) > abs(max_neg)){
                          m[abs(max_pos + v[i])] = m[max_pos] %mod;
                           if(abs(max_pos + v[i]) == max_pos + v[i])
                              m[max_pos + v[i]] = 2*m[max_pos];
                         m[max_pos + v[i]] %= mod;
                          max_pos = abs(max_pos + v[i]);
                          prev = 0;
                    }
                    else if(abs(max_pos + v[i]) < abs(max_neg)){
                          max_pos = abs(max_neg);
                          m[abs(max_neg)] = m[max_neg];
                          m[abs(max_pos)] %= mod;
                          prev = 1;
                    } 
                    if(abs(max_neg) == abs(max_pos + v[i] && prev == 0)){
                        m[abs(max_neg)] += (m[max_neg] + m[max_pos])%mod;
                         if(abs(max_pos + v[i]) == max_pos + v[i])
                            m[max_pos + v[i]] += m[max_pos];

                        max_pos = abs(max_neg);
                        m[max_pos] %= mod;
                    }
                    else{
                        m[abs(max_neg)] = m[max_neg];
                        if(abs(max_neg) == max_pos + v[i])
                            m[max_pos + v[i]] += m[max_pos];
                        max_pos = abs(max_neg);
                        prev = 1;
                    }
                  cout<<m[max_pos]<<" ";
             }
         }
         cout<<m[max_pos]<<endl;
     }
}