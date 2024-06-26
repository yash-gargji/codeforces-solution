#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
          int a, b;
        cin >> a >> b;
        int x, y;
        cin >> x >> y;

        int f = 0;
        if (a <= b && x <= y) 
            f = 1;
        if (b <= a && y <= x) 
          f = 1;
         if(f)
           cout<<"YES\n";
          else{
              cout<<"NO\n";
          }
      }
}