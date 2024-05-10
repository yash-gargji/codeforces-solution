#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         int n;
         cin>>n;

         int k;
         cin>>k;

         if( k != 1 && k < n)
           {
            cout<<-1<<endl;
            continue;
           }
           if(k == 1){
              for(int i = 1;i<= n;i++){
                    cout<<i<<" ";
              }
              cout<<endl;
           }
           else {
            for(int i = 0;i<n;i++){
                cout<<"1 ";
            }
            cout<<endl;
           }
    }
}