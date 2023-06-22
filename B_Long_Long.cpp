#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
          int arr[n];
          for(int i = 0;i<n;i++){
            cin>>arr[i];
          }
            long long int sum = 0;
            int count = 0 ;
            for(int i = 0;i<n;i++){
                if(arr[i] >= 0){
                    sum = sum + arr[i];
                    continue;
                }
                for(int j = i;j<n;j++){
                    i = j;
                    if(arr[j] >0){
                        sum = sum + arr[i];
                        break;
                    }
                    else{
                        sum = sum + abs(arr[j]);
                    }
                    
                }
                count++;
            }
            cout<<sum<<" "<<count<<endl;
    }
    return 0;
}