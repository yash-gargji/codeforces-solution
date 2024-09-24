#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n,m,k;
       cin>>n>>m>>k;
        int a,b,d;
        cin>>a>>b>>d;
        
        int temp = min(a,b);
        b =max(a,b);
        a = temp;
        if(d < a){
           cout<<a - 1;
        }
        else if(d > b){
          cout<<n - b;
        }
        else{
           int num = (b - a)/2;
            cout<<num;
        }
      cout<<endl;
    }
}