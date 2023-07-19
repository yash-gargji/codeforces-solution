#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
           
           long long int n,k;
            cin>>n>>k;
            int arr[n];
            int ans = 0;
            for(int i = 0;i<n;i++){
                cin>>arr[i];
            }
          int f ,r = -1;
             for(int i = 0;i<n;i++){
                 f = i;
                 r = i;
                 int num = arr[i];
                 for(int j = i+1;j<n;j++){
                    if(arr[j] < num){
                        i = j;
                         r = j;
                    }
                    else{
                        break;
                    }
                 }
                 int p = 0;
                 if(f != 0){
                    p = 1;
                 }
                 if(r - f +p>= k){
                    cout<<arr[f];
                    return 0;
                 }
             }
             cout<<*max_element(arr,arr+n);
}