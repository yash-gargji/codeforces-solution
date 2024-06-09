#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int,int>m;
    vector<int>v;

    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
         m[num]++;
    }
    for(auto it:m){
       v.push_back(it.second);
    }
    sort(v.begin(),v.end());
    int ans = 1;
    
    for(int i = 1;i<= n;i++){
        int k = 0,sum = 0;
        int l = -1;
        int h = v.size() - 1;
       while(i*(1 << k) <= n){
           int ind = -1;
           int low = l + 1;
           int high = v.size() - 1;
           while(low <= high){
              int mid = (low + high)/2;
               if(v[mid] >= i*(1 << k)){
                   ind = mid;
                   high = mid - 1;
               }
               else
                low = mid + 1;
           }
          if(ind != -1){
             l = ind;
             sum += i*(1 << k);
             k++;
          }
          else
           break;
       }
      ans = max(ans,sum);
    }
  cout<<ans;
}