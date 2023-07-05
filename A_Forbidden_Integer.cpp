#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
          int n,k,x;
          cin>>n>>k>>x;
          if(x !=  1){
            cout<<"YES\n";
            cout<<n<<endl;
            for(int i = 0;i<n;i++){
                cout<<"1 ";
            }
            cout<<"\n";
          }
          else if(k >= 2 && n%2 == 0){
             cout<<"YES\n"<<n/2<<endl;
             for(int i = 0;i<n/2;i++){
                cout<<"2 ";
             }
             cout<<endl;
          }
          else if(k >= 3 && n >= 3){
               cout<<"YES\n";
               cout<<1+(n-3)/2<<"\n3 ";
               for(int i = 0;i<(n-3)/2;i++){
                    cout<<"2 ";
               }
               cout<<endl;
          }
          else{
            cout<<"NO\n";
          }
     }
     return 0;
}