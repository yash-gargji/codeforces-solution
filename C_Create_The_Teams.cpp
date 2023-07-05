#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
          int n,x;
          cin>>n>>x;
       vector<int>v(n,0);
       for(int i = 0;i<n;i++){
        cin>>v[i];
       }
       sort(v.begin(),v.end());
       int ans = 0;
       auto it = lower_bound(v.begin(),v.end(),x) - v.begin();
       ans = ans + v.end() - it -v.begin();
       int count = 0;
       for(int i = it-1;i>= 0 ;i--){
             count++;
             if(count*v[i] >= x){
                ans++;
                count = 0;
             }
       }
       cout<<ans<<endl;
    }
}