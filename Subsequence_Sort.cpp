#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int ans = 0;

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }

        for(int i = 1;i <n;i++){
           if(arr[i] >= arr[i-1])
             continue;
            int num = 0;
            for(int j = 30;j >= 0;j--){
                int k = (1 << j);
                if((k & arr[i-1]) > 0 && (arr[i] & k) == 0){
                    ans = max(ans,k);
                    arr[i] |= k;
                }
                if(arr[i] >= arr[i-1])
                  break;
            }
        }
      cout<<ans<<endl;
    }
}