#include<bits/stdc++.h>
using namespace std;

int main(){
       int a;
       cin>>a;
       int arr[a];
       int ans = 0;
       for(int i = 0;i<a;i++){
        cin>>arr[i];
        if(arr[i] ){
            ans++;
            arr[i] = -1;
        }
        else{
            arr[i] = 1;
        }
       }
       if(ans == a){
        ans = ans -1;
       }
       int cursum = 0;
       int maxsum = 0;
       for(int i = 0;i<a;i++){
        cursum = cursum + arr[i];
              maxsum = max(maxsum,cursum);
              if(cursum < 0){
                cursum = 0;
              }
       }
       cout<<ans + maxsum;
       return 0;
}