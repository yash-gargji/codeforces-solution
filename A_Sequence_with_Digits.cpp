#include<bits/stdc++.h>
using namespace std;

int main (){
       int t;
       cin>>t;
       while(t--){
       long long int n,k;
        cin>>n>>k;
          long long int num = n;
          multiset<long long int>s;
          for(int i = 1;i<k;i++){
             long long int p = n;
              while(p> 0 ){
                   s.insert(p%10);
                   p = p/10;
              }
              if((*s.begin())*(*((--s.end()))) == 0){
               break;
              }
              num = n + (*s.begin())*(*((--s.end())));
              s.clear();
              n = num;
          }
          cout<<num<<endl;
       }
}