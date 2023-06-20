#include<bits/stdc++.h>
using namespace std;

int main(){
    int  t;
    cin>>t;
    while(t--){
           int n;
           cin>>n;
           int arr[n];
             int one;
             int two;
             int num;
             int num1;
             for(int i = 0;i<n;i++){
                cin>>arr[i];
                if(arr[i] == 1){
                    one = i;
                }
                else if(arr[i] == 2){
                        two = i;
                }
                 else if(arr[i] == n){
                        num = i;
                }
                 else if(arr[i] == n-1){
                        num1 = i;
                }
             }
           
              if(two > one){
                  if(num < one ){
                         cout<<one + 1<<" "<<num+1<<endl;
             }
             else if( num > two ){
                cout<<two + 1<<" "<<num+1<<endl;
             } 
             else{
                cout<<num+1<<" "<<num+1<<endl;
             }       
              }
             else if(two < one ){
                     if(num > one ){
                         cout<<one + 1<<" "<<num+1<<endl;
             }
             else if( num < two ){
                cout<<two + 1<<" "<<num+1<<endl;
             } 
             else{
                cout<<num+1<<" "<<num+1<<endl;
             }       
             }
    }
    return 0;
}