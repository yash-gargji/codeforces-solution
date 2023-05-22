#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    cin>>a;

    while(a--){
      ll x,y;
      cin>>x>>y;
        if(y == 10 ||( y>x)){
            cout<<"0\n";
            continue;
        }
        ll sum =  0;
        ll m = 2;
        ll k = y;
        while(k<=y*10){
                  
                  sum = sum + k%10;
                    k = y*m;
                    m++;
        }
        ll num = x/(y*10);
        ll r = x%(y*10);
        r = r/y;
          ll main = num*sum;
          sum = 0;
          while(r--){
              sum = sum + k%10;
                    k = y*m;
                    m++;
          }
          cout<<main + sum<<endl;
    }
}