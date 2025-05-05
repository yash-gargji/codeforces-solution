#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<vector<int>> v(k);
        
        for(int i = 0;i<n;i++){
            if(s[i] - 'a' < k){
               v[s[i] - 'a'].push_back(i);
            }
        }
        int q;
        cin>>q;

        vector<int>dp(n+1,INT_MAX);
        dp[n] = 1;
        

        for(int i = n-1;i >= 0;i--){
            for(int j = 0;j<k;j++){
                auto itr = lower_bound(v[j].begin(),v[j].end(),i);
                if(itr == v[j].end()){
                   dp[i] = 1;
                   break;
                }
                dp[i] = min(dp[i],1 + dp[(*itr) + 1]);
             }
        }

        while(q--){
            string a;
            cin>>a;

            int flag = 1;
            int ind = 0;
            
            for(auto it:a){
                int i = it - 'a';
                auto itr = lower_bound(v[i].begin(),v[i].end(),ind);
                if(itr == v[i].end()){
                    flag = 0;
                    break;
                }
                ind = (*itr) + 1;
            }
            if(flag == 0){
               cout<<"0\n";
               continue;
            }
            cout<<dp[ind]<<endl;
        }
}