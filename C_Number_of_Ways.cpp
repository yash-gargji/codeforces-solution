#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    int arr[a];
    long long int sum = 0;
    for(int i = 0;i<a;i++){
        cin>>arr[i];
        sum = sum + arr[i];
    }
    if(a == 2 || sum%3 != 0){
      cout<< 0;
      return 0;
    }
    long long int x = sum/3;
       int count1 = 0;
          int  count2 = 0;
          long long int m = 0; 
          int f = 0;;
        for(int i = 0;i<a;i++){
                m  = m + arr[i];
                if(m == x){
                   f = i;
                   break;
                }
        }
        int r = a;
        m = 0;
        for(int i = a-1;i>=0;i--){
                 m  = m + arr[i];
                if(m == x){
                   r = i;
                   break;
                }
        }
        m = 0;
        int l = f;
        for(int i = f+1;i<r;i++){
              m = m + arr[i];
              if(m == x){
                l = i;
                break;
              }  
              if(m == 0){
              count1++;
              }
        }
        m = 0;
         for(int i = l+1;i<r;i++){
              m = m + arr[i];
              if(m == 0){
              count2++;
              }
        }
        cout<<(count1 +1)*(count2 +1);
}