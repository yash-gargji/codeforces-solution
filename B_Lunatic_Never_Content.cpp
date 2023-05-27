#include<bits/stdc++.h>
using namespace std;

int  main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        
        int arr[a];
        for(int i = 0;i<a;i++){
               cin>>arr[i];
        }
           if(a == 1){
            cout<<"0\n";
            continue;
        }
           int arr1[a/2];
           int i = 0,j = a-1;
           while(i<j){
                  arr1[i] = max(arr[i],arr[j]) -  min(arr[i],arr[j]);
                  i++;
                  j--;
           }
           
           int gcd1 = arr1[0];
           for(int i = 1;i<a/2;i++){
               gcd1 = __gcd(gcd1,arr1[i]);
                
           }
           cout<<gcd1<<endl;
    }
}
