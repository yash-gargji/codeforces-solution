#include<bits/stdc++.h>
using namespace std;

 
int main(){
     int t;
     cin>>t;

     while(t--){
          int n;
          cin>>n;
          vector<int>a(n),b(n);
          int p = 0 , neg = 0;
          int sum1 = 0, sum2 = 0;

          for(int i = 0;i<n;i++){
              cin>>a[i];
          }
          for(int i = 0;i<n;i++){
              cin>>b[i];
              if(a[i] == 1 && b[i] == 1){
                 p++;
              }
              else if(a[i] == -1 && b[i] == -1){
                   neg++;
              }
              else if(a[i] == 1){
                  sum1++;
              }
              else if(b[i] == 1){
                sum2++;
              }
          }
         if(sum1 >= sum2){
             int num = sum1 - sum2;
             sum1 -= min(num,neg);
             neg = neg - min(num,neg);
         }
         else{
             int num = sum2 - sum1;
             sum2 -= min(num,neg);
             neg = neg - min(num,neg);
            
         }
         sum1 = sum1 -  neg/2 - neg%2;
         sum2 -= neg/2;

         if(sum1 <= sum2){
             int num = sum2 - sum1;
             sum1 += min(num,p);
             p = p - min(num,p);
         }
         else{
            int num = sum1 - sum2;
             sum2 += min(num,p);
             p = p - min(num,p);
         }
         sum1 += p/2;
         sum2 += p/2;

         cout<<min(sum1,sum2)<<endl;
     }
}