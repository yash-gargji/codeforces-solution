  #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int arr[a];
        for(int i = 0;i<a;i++){
            cin>>arr[i];
        }
           long long int sum = 0;

           sum = sum + arr[0];

           for(int i = 1;i<a;i++){
              if(arr[i] > 0 ){
                 if(arr[i-1] < 0){
                    sum = sum + arr[i];
                 }
                 else{
                       if(arr[i] > arr[i-1]){
                     sum = sum + arr[i] - arr[i-1];
                      
                 }
                 else{
                    arr[i] = arr[i-1];
                 }
                 }
              }
              else{
                 if(arr[i-1] > 0){
                    sum = sum + arr[i];
                 }
                 else{
                      if(arr[i] > arr[i-1]){
                     sum = sum + arr[i] - arr[i-1];
                      
                 }
                 else{
                    arr[i] = arr[i-1];
                 }
                 }
              }
           }
           cout<<sum<<endl;
    }
    return 0;
}