#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          long long int num;
          cin>>num;
           
           vector<int>v;
           if(num < 10){
               cout<<"NO\n";
               continue;
           }

           long long int k = num;

            while(k != 0){
                v.push_back(k%10);
                 k = k/10;
            }
           
            int ans = 1;
           for(int i = 0;i<v.size() - 1;i++){
                if(i != 0 && v[i] == 0){
                    ans = 0;
                    break;
                }
                if(i != 0)
                  v[i]--;
                  int f = 0;
              for(int j = 5;j<=9;j++){
                   for(int l = 5;l <= 9;l++){
                       if((l + j)%10 == v[i]){
                            f = 1;
                            break;
                       }
                   }
               }    
               if(f == 0){
                 ans = 0;
                 break;
               }
           }
          if(v[v.size() - 1] != 1){
              ans = 0;
          }
          if(ans)  cout<<"YES\n";
          else{
              cout<<"NO\n";
          }
     }
}