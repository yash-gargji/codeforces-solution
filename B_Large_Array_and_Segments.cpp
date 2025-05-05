#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k,x;
         cin>>n>>k>>x;

         long long ans = 0;
         int sum = 0;
         vector<int>pre(n);

         for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             pre[i] = num;
             if(i != 0) 
               pre[i] += pre[i-1];
         }

         int l = 1;
         int r = k;
         int num = n+1;

         while(l <= r){
            int mid = (l + r)/2;

            if(mid*pre[n-1] >= x){
                 num = mid;
                 r = mid-1;
            }
            else{
               l = mid + 1;
            }
         }
         if(num == n+1){
             cout<<"0\n";
             continue;
         }
         l = 0;
         r = n;
         int op = -1;

         while(l <= r){
             int mid = (l + r)/2;
             int odd = (num-1)*pre[n-1] + pre[n-1] - (mid == 0 ? 0 : pre[mid-1]);

             if(odd >= x){
                op = mid;
                l = mid +1;
             }
             else{
               r = mid - 1;
             }
         }
         cout<<(k - num)*n + op + 1<<endl;
         
    }
}