#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int ans = 0; 
       int n;
       cin>>n;
       int ind = -1;

       for(int i = 2;i<=n;i++){
           int num = 0;

             for(int j = 1;j<= n;j++){
                  if(j*i > n)
                    break;
                  num += j*i;
             }
             if(num >= ans){
                 ind = i;
                 ans = num;
             }
       }
       cout<<ind<<endl;
    }
}