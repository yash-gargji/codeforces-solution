#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
          int k;
          cin>>k;
          vector<int>arr(k);

          for(int i = 0;i<k;i++){
              cin>>arr[i];
              // cout<<arr[i]<<" ";
              for(int j = 0;j<arr[i]-1;j++){
                  int num;
                  cin>>num;
              }
          }
          vector<int>bit(31);
         for(int i = k-1; i >= 0;i--){
            //   cout<<arr[i]<<" ";
              int ind = 31;
               while(ind > 0){
                   ind--;
                  if(bit[ind]){
                     continue;
                  }
                  else if(arr[i] - (1 << ind) >= 0){
                      bit[ind] = 1;
                      arr[i] -= (1 << ind);
                  }
               }
         }
        int ans = 0;

        for(int i = 30;i>= 0;i--){
             if(bit[i])
              ans += 1 << i;
        }
        cout<<ans<<endl;
      }
}