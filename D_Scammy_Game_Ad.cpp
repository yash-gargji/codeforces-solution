#include <bits/stdc++.h>
using namespace std;
#define int long long
   
int calc(char c,int num,int m){
   if(c == '+')
     return m;
    return num*(m-1);
}

// int func(int ind, vector<pair<char,char>> &s, vector<pair<int,int>>&v, vector<map<vector<long long> ,long long>> &dp,int num,int x,int y){
//     if(ind == s.size())
//       return 0;
//     if(dp[ind].count({num,x,y}) != 0)
//       return dp[ind][{num,x,y}];
//      int ans = -1e18;

//      int a = calc(s[ind].first,x,v[ind].first) + calc(s[ind].second, num + y,v[ind].second);
//      int b = calc(s[ind].first,num+ x,v[ind].first) + calc(s[ind].second,y,v[ind].second);

//      ans = max(ans,a + func(ind + 1,s,v,dp,a,x,num + y));
//      ans = max(ans,b + func(ind + 1,s,v,dp,b,x + num,y));
  
//      return dp[ind][{num,x,y}] = ans;
     
// }

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<char,char>>s(n);
        vector<pair<int,int>>v(n);
        vector<map<vector<long long>,long long>>dp(n);

        for(int i = 0;i<n;i++){
           cin>>s[i].first;
           cin>>v[i].first;
           cin>>s[i].second;
           cin>>v[i].second;
        }
        int x = 1,y = 1;

        int dir = 0;

        for(int i = 0;i<n;i++){
           for(int j = i+1;j<n;j++){
               if(s[j].first == 'x' && s[j].second == '+'){
                  dir = 0;
                  break;
               }
               if(s[j].first == '+' && s[j].second == 'x'){
                  dir = 1;
                  break;
               }
               if(s[j].first == 'x' && s[j].second == 'x'){
                  if(v[j].first > v[j].second){
                     dir = 0;
                     break;
                  }
                  else if(v[j].second > v[j].first){
                      dir = 1;
                      break;
                  }
               }
           }
          int a = calc(s[i].first,x,v[i].first);
          int b = calc(s[i].second,y,v[i].second);
          if(dir == 0)
            x += a + b;
          else 
            y += a + b;
        }
      cout<<x + y<<endl;
    }
}
