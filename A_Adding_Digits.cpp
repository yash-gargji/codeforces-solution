#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  int num = (a * 10) % b;
  num = b - num;
     if((a*10)%b == 0){
      cout<<a;
      for(int i = 0 ;i<n;i++){
            cout<<"0";
      }
     }
  else if (num > 9){
    cout<<"-1";
  } 
  else{
    cout<<a*10+num;
    for(int i = 1;i<n;i++){
      cout<<"0";
    }
  }
  }