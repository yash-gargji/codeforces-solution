#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       long long  int n,k;
        cin>>n>>k;
        vector<int>ans(n);

        for(int i = 0;i<n;i++){
            ans[i] = i+1;
        }
        int l = 0;
        int r = n-1;

        while(l < r){
             if((r - l)*2 <= k){
                 k = k - (r - l)*2;
                 swap(ans[l],ans[r]);
                 l++;
                 r--;
             }
             else{
                r--;
             }
        }
      if(k != 0)
        cout<<"No\n";
       else{
          cout<<"Yes\n";
          for(int i = 0;i<n;i++){
              cout<<ans[i]<<" ";
          }
          cout<<endl;
       }
    }
}