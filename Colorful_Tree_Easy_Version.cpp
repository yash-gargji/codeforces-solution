#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>ve(n);

        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            ve[u-1]++;
            ve[v-1]++;
        }
       int ans = 0;

       for(int i = 0;i<n;i++){
           if(ve[i] >= 2){
               ans += 2;
           }
           else{
            ans += 3;
           }
       }
       cout<<ans<<endl;
    }
}