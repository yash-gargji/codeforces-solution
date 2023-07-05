#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    std::cin>>n>>d;
    pair<int,int>p[n];  

    long long int  ans  = 0;
   
   for(int i = 0;i<n;i++){
        int num1,num2;
       std::cin>>num1>>num2;
        p[i] = {num1,num2};
   }
  sort(p,p+n);
    long long int slid = p[0].second;
    ans = slid;
       int k  = 0;
  for(int  i = 1;i<n;i++){
          if(p[i].first - p[k].first < d){
             slid  = slid + p[i].second; 
          }
          else{
               for(int j = k ;j< i;j++){
                    k = j;
               if(p[i].first - p[j].first < d){
                         break;
               } 
               else{
                    slid = slid - p[j].second;
               }
          }
          if(slid == 0){
               k = i;
          }
          slid  =  slid + p[i].second;     
  }
   ans = max(ans,slid); 
  }
 cout<<ans;
  return 0;
}