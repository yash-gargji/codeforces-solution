#include<bits/stdc++.h>
using namespace std;

int main(){

      int n,odd = 0,even = 0;
      cin>>n;
       
          for(int i = 0;i<n;i++){
               int num;
               cin>>num;
                  if(num %2 == 1){
                    odd++;
                  }
                  else{
                    even++;
                  }
          }
           cout<<min(odd,even) + (odd - min(odd,even))/3;
            
}