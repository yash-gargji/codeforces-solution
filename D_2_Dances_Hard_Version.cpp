#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(n),pre(n),suff(n);

        for(int i = 0;i<n-1;i++){
            cin>>a[i];
        }
        for(int i = 0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.begin() + n -1);
        sort(b.begin(),b.end());
        int prev = 0;
        
        for(int i = 0;i<n-1;i++){
            auto it = upper_bound(b.begin()+i,b.end(),a[i]) - b.begin();
            prev = max(prev,it - i);
            pre[i] = prev;
        }
        prev = 0;
        for(int i = n-2;i >= 0;i--){
            auto it = upper_bound(b.begin()+i+1,b.end(),a[i]) - b.begin();
            prev = max(prev,it - i-1);
            suff[i] = prev;
        }
        int ans = 0;
        prev = 0;
        int j = 0;

        for(int i = 0;i<n;i++){
             j = max(j,i);
             while(j < n && b[j] - 1 <= prev && b[j] <= a[i])
               j++;
             if(prev == m)
                break;
            if(i == n-1)
              a[n-1] = prev;
            
            if(j != n && b[j] <= a[i]){
               int num = max(suff[i],j-i);
               if(i != 0)
                 num = max(num,pre[i-1]);
               ans += num * (min(m,b[j]-1) - prev);
               prev = min(m,b[j]-1);
               j++;
               i--;
            }
            else {
                int num = suff[i];
                if(i != 0){
                   num = max(num,pre[i-1]);
                }
                auto it = upper_bound(b.begin()+i,b.end(),min(m,a[i])) - b.begin();
                num = max(num,it - i);
                ans += num*(min(m,a[i]) - prev);
                prev = min(m,a[i]);
            }
        }
        if(prev < min(m,b[n-1] - 1)){
           ans += pre[n-2]*(min(m,b[n-1] - 1) - prev);
           prev = min(m,b[n-1]-1);
        }
        ans += max(1ll,pre[n-2])*(m - prev);
        
       cout<<ans<<endl;
    }
}