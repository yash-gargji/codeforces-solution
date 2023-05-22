#include<bits/stdc++.h>
using namespace std;

int main(){
     int a;
     cin>>a;
     while(a--){
        int x,y;
        cin>>x>>y;
        int k = 0;
        
        int flag = 0;
        while(k<= x/2 ){
               int num = x-  k;
               if((k*(k-1))/2 + (num*(num-1))/2 == y){
                          flag = 1;
                          break;
               }
               k++;
        }
        if(flag == 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i = 0;i<k;i++){
                cout<<"1 ";
            }
            for(int i = k;i<x;i++){
                cout<<"-1 ";
            }
            cout<<endl;
        }
     }
     return 0 ;
}