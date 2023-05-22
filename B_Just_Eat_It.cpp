#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int a;
        cin>>a;
        int arr[a];
         long long int sum = 0;
         int x = 0,y = 0;
        for(int i =0;i<a;i++){
            cin>>arr[i];
            sum = sum + arr[i];
            if(arr[i] >= 0){
                x++;
            }
            else{
                y++;
            }
        }
        if(x == a ){
            cout<<"YES\n";
            continue;
        }
        else if(y == a){
                cout<<"NO\n";
                continue;
            }
             if(sum <= *max_element(arr,arr+a)){
                cout<<"NO\n";
                continue;
             }
         long long int s = 0;
        long long int max1 = 0;
         if(arr[0] >= arr[a-1]){
             int r = a-1;
             for(int i = 0; i< r;i++){
                  s = s + arr[i];
                  max1 = max(max1,s);
                  if(s <= 0){
                    s = 0;
                    r = a;
                  }
                  else {
                    continue;
                  }
             }
             if(max1 >= sum ){
                cout<<"NO\n";
             }
             else{
                cout<<"YES\n";
             }
         }
         else{
              int r = 0;
             for(int i = a-1; i> r;i--){
                  s = s + arr[i];
                  max1 = max(max1,s);
                  if(s <= 0){
                    s = 0;
                    r = -1;
                  }
                  else {
                    continue;
                  }
             }
             if(max1 >= sum ){
                cout<<"NO\n";
             }
             else{
                cout<<"YES\n";
             }
         }
         
        }
        
    }
