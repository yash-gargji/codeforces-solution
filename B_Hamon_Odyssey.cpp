#include<bits/stdc++.h>
using namespace std;
   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
       int p;
       cin>>p;
       while(p--){
               int n;
               cin>>n;
               int arr[n];
               for(int i = 0;i<n;i++){
                   cin>>arr[i];
               }
               int count  = 0;
               int k = arr[0];
               int flag = 0;
               for(int i = 1;i<n;i++){
                    k = k&arr[i];
                    if(k == 0){
                        flag = 1;
                        count++;
                           if(i+1 != n){
                            k = arr[i+1];
                            i++;
                           }    
                    }
               }
               if(flag == 0){
                cout<<"1\n";
               }
               else{
                cout<<count<<endl;
               }
       }
}