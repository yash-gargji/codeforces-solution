#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
         long long int x,y,k;
          cin>>x>>y>>k;

         while(x != 1 && k > 0){
             long long int num = y - (x%y);
             x += min(num,k);
              k = k - min(k,num);

              while(x%y == 0){
                  x = x/y;
              }
         }
        x += k%(y-1);
        cout<<x<<endl;
      }
}