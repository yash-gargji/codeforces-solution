#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if(max(x2,x1) - min(x2,x1) == max(y2,y1) - min(y1,y2)){

        int a = x2-x1;
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }
    else if(x1 == x2 || y1 == y2){
        int max1 = max(y2,y1) - min(y1,y2);
        int max2 = max(x2,x1) - min(x2,x1);
      int a =   max(max1,max2);
      if(y2 == y1){
        cout<<x2<<" "<<y2+a<<" "<<x1<<" "<<y1+a;
      }
      else{
        cout<<x2+a<<" "<<y2<<" "<<x1+a<<" "<<y1;
      }
    }
    else{
        cout<<"-1";
    }
    return 0;
}