#include <bits/stdc++.h>
using namespace std;

vector<int> func(int limit,string s){
    int n = s.size();
    vector<int>ans(n,-1);
       int prev = 0;
       int count = 1;
       int ind = n;
       for(int i = 0;i<n;i++){
          if(s[i] - '0' >= prev && s[i] - '0' < limit){
             ans[i] = count;
             prev = s[i] - '0';
             ind = i;
          }
       }
       prev = limit;
       count = 2;
       for(int i = 0;i<n;i++){
          if(s[i] - '0' >= prev){
             ans[i] = count;
             prev = s[i] - '0';
          }
       }
       prev = limit;
       count = 1;
        for(int i = ind;i<n;i++){
          if(s[i] - '0' == limit &&  ans[i] == -1){
             ans[i] = count;
             prev = s[i] - '0';
          }
       }
    return ans;
}

 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>ans;
        int flag = 0;

        for(int i = 0;i<=9;i++){
            vector<int>v = func(i,s);
            flag = 1;
            for(int j = 0;j<n;j++){
                if(v[j] == -1){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans = v;
                break;
            }
        }
        
        if(!flag)
            cout<<"-\n";
        else{
            for(int i = 0;i<n;i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
}
