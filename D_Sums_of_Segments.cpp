#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
        int n;
        cin >> n;
        int arr[n];
        int sum = 0;
        vector<int>all(n),pre(n),tpre(n);
        vector<int>space;
        int count = 0;
        space.push_back(0);
        for(int i = 0;i<n;i++){
            count += n - i;
            cin>>arr[i];
           sum += (n - i)*arr[i];
           pre[i] = arr[i];
           if(i > 0)
             pre[i] += pre[i-1];
            tpre[i] = pre[i];
            if(i > 0){
              tpre[i] += tpre[i-1];
            }
            space.push_back(count);
        }
        all[0] = sum;
        
        for(int i = 1;i<n;i++){
           sum -= (n - i + 1)*arr[i-1];
           all[i] = sum;
           all[i] += all[i-1];
        }
        int q;
        cin>>q;
        for(int i = 0;i<q;i++){
           int l,r;
           cin>>l>>r;
           int num = 0;
           auto it1 = lower_bound(space.begin(),space.end(),l) - space.begin();
           auto it2 = lower_bound(space.begin(),space.end(),r) - space.begin();
           it1--;
            // cout<<it1<<" "<<it2<<endl;
              if(space[it2] == r && it2 -it1 >= 2)
                num = all[it2-1] - all[it1];
              else if(it2 - it1 > 2)
                 num = all[it2-2] - all[it1];
           if(it1 + 1 == it2){
              l = l - space[it1];
              r = r - space[it1];    
              num += tpre[it1 + r-1];
              if(it1 + l - 2 >= 0){
                 num -= tpre[it1 + l-2];
              }
              num -= (r - l + 1)*((it1 > 0 ? pre[it1-1] : 0));
           }
           else{
              l = l - space[it1];
              num += tpre[n-1];
              if(it1 + l - 2 >= 0)
                 num -= tpre[it1 + l - 2];
              num -= (n - l + 1 - it1)*((it1 > 0 ? pre[it1-1] : 0));
              if(space[it2] != r){
                  it2--;
                  r = r - space[it2];    
                  num += tpre[it2 + r -1];
                if(it2 - 1 >= 0)
                    num -= tpre[it2 - 1];
                num -= (r)*((it2 > 0 ? pre[it2-1] : 0));
              }
           }
          cout<<num<<endl;
        }
    return 0;
}