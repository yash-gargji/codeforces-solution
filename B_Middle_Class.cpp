#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       long long int n,m;
        cin>>n>>m;
        long long int product,sum = 0;
          int arr[n];
          for(int i = 0;i<n;i++){
               cin>>arr[i];
          }
          sort(arr,arr+n);
          reverse(arr,arr+n);
          int count = 0;
          for(int i = 0;i<n;i++){
                sum = sum + arr[i];
                count++;
                product = count*m;
                if(sum< product){
                    count--;
                    break;
                }
          }
          cout<<count<<endl;
    }
}