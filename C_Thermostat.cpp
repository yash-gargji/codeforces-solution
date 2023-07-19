#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
       int t;
       cin>>t;
       while(t--){
             long long int l,r,x,a,b;
             cin>>l>>r>>x>>a>>b;
           if(b < l || b > r){
            cout<<"-1\n";
            continue;
           }
           else if(a == b){
            cout<<"0\n";
            continue;
           }
           if(abs(a-b) >= x){
            cout<<1<<endl;
           }
           else if(b > a){
                 if(a-x >= l || b + x <= r){
                    cout<<"2\n";
                 }
                 else if(a+x <= r && b - x >= l){
                    cout<<"3\n";
                 }
                 else{
                    cout<<"-1\n";
                 }
           }
           else{
              if(a+x <= r || b - x >= l){
                cout<<"2\n";
              }
              else if(a-x >= l && b +x <= r){
                    cout<<"3\n";
                 }
                 else{
                    cout<<"-1\n";
                 }
           }

       }
}