#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){

         long long int n,k;
          cin>>n>>k;
            long long int k2 = k;
           int p1 ,p2;
           cin>>p1>>p2;
          int p[n],a[n];
          long long s1 = 0,s2 = 0,sum1 = 0,sum2 = 0;
          
          for(int i = 0;i<n;i++){
             cin>>p[i];
          }
          for(int i = 0;i<n;i++){
             cin>>a[i];
          }
          int count = 0 ;
          while( count < min(k,n)){
               s1 = max(s1,sum1 + (k - count)*a[p1-1]);
               sum1 += a[p1-1];
               count++;
               p1 = p[p1-1];
          }
          count = 0;
           while( count < min(k,n)){
               s2 = max(s2,sum2 + (k - count)*a[p2-1]);
               sum2 += a[p2-1];
               count++;
               p2 = p[p2-1];
          }
          if(s1 > s2){
             cout<<"Bodya\n";
          }
          else if(s1 <  s2){
             cout<<"Sasha\n";
          }
          else{
              cout<<"Draw\n";
          }
      }

}