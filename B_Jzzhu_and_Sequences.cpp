#include<bits/stdc++.h>
using namespace std;

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x,y;
    cin>>x>>y;
   long long int n;
    cin>>n;
    if(x == y){
            cout<<( y + 1000000007)%1000000007;
            return 0;
}
    if(n == 1){
        cout<<(x + 1000000007)%1000000007;
        return 0;
    }
    else if(n == 2){
          cout<<(y + 1000000007)%1000000007;
          return 0;
    }
     int num = 2;
    long long int z ;
      while(1){
            z = y-x;
            x = y;
            y = z;
            num++;
            if(num == n){
                 break;
            }
      }
      cout<<(z + 1000000007)%1000000007;
      return 0;
}