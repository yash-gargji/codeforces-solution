#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n,k,q;
          cin>>n>>k>>q;
           k++;
        int dis[k],time[k];

          dis[0] = 0;
          time[0] = 0;

          for(int i = 1;i<k;i++){
              cin>>dis[i];
          }
           for(int i = 1;i<k;i++){
              cin>>time[i];
          }

          for(int i = 0;i<q;i++){
            int num ;
            cin>>num;
            int l = 0;
            int r = k-1;    
             int ind = 0;

             while(l <= r){
                  int mid = (l+r)/2;

                  if(dis[mid] <=num){
                       ind = mid;
                       l = mid+1;
                  }
                  else{
                      r = mid - 1;
                  }
             }
             if(ind == k-1){
                   cout<<time[k-1]<<" ";
                   continue;
             }
           long long  int ans = time[ind] +  1ll*(num - dis[ind])*(time[ind+1] - time[ind])/(dis[ind+1] - dis[ind]);
             cout<<ans<<" ";
          }
          cout<<endl;
     }
}