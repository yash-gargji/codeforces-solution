#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
     long long int n,c;
     cin>>n>>c;
     int arr[n];
     vector<pair<int,int>>v(n);
     vector<long long >pre(n);
     map<int,int>m;
     int ans = 0;

     for(int i = 0;i<n;i++){
         cin>>arr[i];
         v[i].first = arr[i] + min(1ll*i+1,n - i);
         v[i].second = i;
     }  
     sort(v.begin(),v.end());

     for(int i = 0;i<n;i++){
         pre[i] = v[i].first;
         m[v[i].second] = i;
         if(i != 0)
           pre[i] += pre[i-1];
     }

     for(int i = 0;i<n;i++){  
         int num = arr[i] + i + 1;
         if( num > c)
           continue;
         ans = max(ans,1);
          int k = c - num;
          int low = 0;
          int high = n-1;

          while(low <= high){
             int mid = (low + high)/2;
             int off = 0;
             int point = 1;
             if(mid >= m[i]){
                off = v[m[i]].first;
                point = 0;
             }
             if(pre[mid] - off <= k){
                ans = max(ans,mid + 1 + point);
                low = mid + 1;
             }
             else{
                high = mid - 1;
             }
          }
      }
      cout<<ans<<endl;
     
   }
}