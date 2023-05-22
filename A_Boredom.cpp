#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    map<int,int>m;
     
    for(int i = 0;i<a;i++){
         int x;
         cin>>x;
         m[x]++; 
    } 
    long long int sum  = 0;
       for(auto it = m.rbegin();it != m.rend();it++){
              long long int sum1 = 0,sum2 = 0,sum3= 0;
               sum1 = (it->second)*(it->first);
              auto itr = m.find(it->first -1);
              if(itr == m.end()){
                sum2 = 0;
              }
              else{
                sum2 = (itr->second)*(itr->first);
              }
               auto p = m.find(it->first -2);
                 if(p == m.end()){
                sum3 = 0;
              }
              else{
                sum3 = (p->second)*(p->first);
              }
              if(sum1 >= sum2){
                sum = sum + sum1;
                m.erase(itr);
              }
              else if(sum2 >= sum1 + sum3){
                    sum = sum + sum2;
                      m[it->first] = 0;
                      m.erase(p);
              }
       }
    
    cout<<sum;
  return 0;
}

