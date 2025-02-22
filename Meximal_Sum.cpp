#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
     int t;
     cin>>t;
     
     while(t--){
          int n;
          cin>>n;
          
          int arr[n];
          int pre[n];

          for(int i = 0;i<n;i++){
              cin>>arr[i];
              pre[i] = arr[i];
              if(i != 0)
                pre[i] += pre[i-1];
          }
          map<int,int>m;
          vector<int>s(n);
          int num = 0;
          for(int i = n-1;i >= 0;i--){
             m[arr[i]]++;
             while(m[num] > 0)
               num++;
             s[i] = num;
          }
          map<int,int>p;
          map<int,vector<int>>ind;
          map<int,vector<int>>mex;
          int ma = -1e18,mi = 1e18;

          for(int i = 0;i<n;i++){
            
            p[arr[i]]++;
            while(p[num] > 0)
            num++;
            mex[num].push_back(i);
            ind[arr[i]].push_back(i);
            if(i == 0 || i == n-1)
              continue;
            // if()
          }
     }
}