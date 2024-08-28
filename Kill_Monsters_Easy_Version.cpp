#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,x,k;
       cin>>n>>x>>k;
       int arr[n];
       map<int,int>m;
       
       for(int i = 0;i<n;i++){
          cin>>arr[i];
          m[arr[i]]++;
       }
       sort(arr,arr+n);
       vector<int>p,d,v;

       for(auto it:m){
          v.push_back(it.first);
          if(p.size() > 0){
             p.push_back(1 + p[p.size() - 1]);
          }
          else{
            p.push_back(1);
          }
          if(d.size() > 0){
            if(it.second >=2){
               d.push_back(2 + d[d.size() - 1]);
            }
            else{
                 d.push_back(d[d.size() - 1]);
            }
          }
          else{
            if(it.second >=2){
               d.push_back(2);
            }
            else{
                 d.push_back(0);
            }
          }
       }
       if(v[0] >= x){
         x = x*k;
         int ans = 0;
         auto it = lower_bound(v.begin(),v.end(),x) - v.begin();
         it--;
         if(it >= 0){
            ans = p[it];
         }
         cout<<ans<<endl;
       }
       else{
        auto start = lower_bound(v.begin(),v.end(),x) - v.begin();
        start--;
         int ans = 0;
        //  auto itr = lower_bound(v.begin(),v.end(),x*k) - v.begin();
        //  itr--;
        //  if(itr >= 0){
        //      ans = p[itr];
        //  }
         for(int i = start;i >= 0;i--){
             int num = p[i];
             int lop = k*x;
             auto it = lower_bound(v.begin(),v.end(),lop) - v.begin();
             it--;
             if(it > start){
                num = p[it];
                int sum = d[start] - d[i];
                sum /= 2;
                num += sum;
             }
             else{
                num = p[start];
                int sum = d[it] - d[i];
                sum /= 2;
                num += sum;
             }
            ans = max(ans,num);
            x = v[i];
         }
            int num = p[0];
             int lop = k*x;
             auto it = lower_bound(v.begin(),v.end(),lop) - v.begin();
             it--;
             if(it > start){
                num = p[it];
                int sum = d[start];
                sum /= 2;
                num += sum;
             }
             else{
                num = p[start];
                int sum = d[it];
                sum /= 2;
                num += sum;
             }
            ans = max(ans,num);
         cout<<ans<<endl;
       }
    }
}