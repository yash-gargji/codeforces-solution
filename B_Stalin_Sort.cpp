#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
       int arr[n];
       int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
           int a = 0;
           for(int j = i+1;j<n;j++){
               if(arr[j] > arr[i])
                 a++;
           }
          ans = min(ans,i + a);
        }
      cout<<ans<<endl;
    }
}
