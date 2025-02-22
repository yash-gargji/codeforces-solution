#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        int x;
        cin>>x;
        int ans = 1;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        // for(int i = 0;i<n;i++){
        //     cin>>arr[i];
        // }
        for(int i = 0;i<n;i++){
            int flag = 1;
            int prev = arr[i];

            for(int j = i+1;j<n;j++){
                if(arr[j] >= prev){
                   ans = max(ans,j - i + 1);
                   prev = arr[j];
                }
                else if(flag != 0 && x*arr[j] >= prev){
                    
                       ans = max(ans,j - i + 1);
                       flag = 0;
                       prev = arr[j] * x;
                    
                }
                else 
                  break;
                
            }
        }
      cout<<ans<<endl;
    }
}