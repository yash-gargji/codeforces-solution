#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[500][500][2];
int pos[500],d[500];

int func(int ind,int dir,int t,int n,int k){
     
     if(ind == n-1 && dir == 0 )
        return 1;
     if(ind == 0 && dir == 1)
        return 1;
     if(dp[ind][t][dir] != -1)
       return dp[ind][t][dir];
     dp[ind][t][dir] = 0;
    if(dir == 1 && ind != 0){
        int num = pos[ind] - pos[ind-1] + t;
        num %= k;
        int di = dir;
        if(d[ind-1] == num){
            di = !dir;
        }
       dp[ind][t][dir] = func(ind-1,di,num,n,k);
    }
    else if(dir == 0 && ind != n-1){
            int num = pos[ind+1] - pos[ind] + t;
            num %= k;
            int di = dir;
            if(d[ind+1] == num){
                di = !dir;
            }
            dp[ind][t][dir] = func(ind+1,di,num,n,k);
    }
  return dp[ind][t][dir];
}

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));

        for(int i = 0;i<n;i++){
            cin>>pos[i];
        }
        for(int i = 0;i<n;i++){
            cin>>d[i];
        }
        int q;
        cin>>q;

        while(q--){
            int p;
            cin>>p;
            auto it = lower_bound(pos,pos+n,p) - pos;
            if(p > pos[n-1]){
               cout<<"YES\n";
               continue;
            }
            int num = pos[it] - p;
            num %= k;
            int dir = 0;
            if(d[it] == num){
                dir = 1;
            }
            int ans = func(it,dir,num,n,k);
            if(ans)
               cout<<"YES\n";
            else 
              cout<<"NO\n";
        }
        
    }
}