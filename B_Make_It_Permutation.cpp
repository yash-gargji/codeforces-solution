#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>ans;

        if(n % 2 == 0){
           int num = 0;
           
           for(int i = 2;i<= n;i++){
              ans.push_back({i,1,n-num});
              if(num != 0){
                 ans.push_back({i,1 + num,n});
              }
              num++;
           }
        }
        else{
           int num = 0;
           ans.push_back({1,2,n});
           int k = (n+1)/2;
           for(int i = 2;i<= n;i++){
              ans.push_back({i,1,n-num});
              num++;
              if(i > (n+1)/2){
                 ans.push_back({i,1 + k,n});
                 k--;
              }   
           }
        }

        cout<<ans.size()<<endl;

        for(int i = 0;i<ans.size();i++){
            cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
        }
    }
}