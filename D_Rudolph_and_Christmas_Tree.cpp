#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int main(){
       int t;
       cin>>t;
       while(t--){
              int n;
              double b,h;
              cin>>n>>b>>h;
              int arr[n];
              for(int i = 0;i<n;i++){
                     cin>>arr[i];
              }
              sort(arr,arr+n);
              double k  = b/h;
              double sum = 0;
              double area = b*h*0.5;
              for(int i = 0;i<n;i++){
                if(i == n-1 || arr[i] + h <= arr[i+1] ){
                     sum += area;
                     continue;
                }
                  if(arr[i] + h > arr[i+1]){
                      double num = b - k*( arr[i+1] - arr[i]);
                      sum += area -  (double)(num*(arr[i] + h - arr[i+1])*0.5);
                  }
              }
              cout<< fixed << setprecision(7)<<sum<<endl;
       }
}