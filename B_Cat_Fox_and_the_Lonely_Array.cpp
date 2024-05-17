#include<bits/stdc++.h>
using namespace std;

void f(int num,vector<int>&v,int flag){
     int  k = 1;
        int ind = 0;
            while(k << ind <= num){
                if((k << ind)&num){
                     v[ind] += flag;
                }
                ind++;
            }
}
int lop(vector<int>&v){
      int ans = 0;

      for(int i = 0;i<20;i++){
           if(v[i]){
             ans += (1 << i);
           }
      }
    return ans;
}

int  main(){
     int t;
     cin>>t;
     
     while(t--){
          int n;
          cin>>n;
          int arr[n];

          for(int i = 0;i<n;i++){
             cin>>arr[i];
          }
          
          int low  =1;
          int high =  n;
          int ans = n;

          while(low <= high){
              int mid = (low + high)/2;
                vector<int>v(20);
                int flag = 1;
                int prev = -1;

                for(int i = 0;i<n;i++){
                     f(arr[i],v,1);
                      if(i == mid-1){
                         prev = lop(v);
                      }
                      else if( i >= mid){
                          f(arr[i - mid],v,-1);
                          int num = lop(v);
                          if(prev != num){
                              flag = 0;
                              break;
                          }
                          else 
                            prev = num;
                      }
                }
              if(flag){
                 ans = mid;
                 high = mid - 1;
              }
              else {
                 low = mid + 1;
              }
            
          }
        cout<<ans<<endl;
          
     }
}