#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int b[n];
        vector<pair<int,int>>v(n);
         
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            v[i] = {num,i};
        }
        sort(v.begin(),v.end());

        for(int i = 0;i<n;i++){
            cin>>b[i];
        }
        sort(b,b+n);

        vector<int>ans(n);

        for(int i =0;i<n;i++){
            ans[v[i].second] = b[i];
        }

        for(int i = 0;i<n;i++){
            cout<<ans[i]<<" ";
        }
      cout<<endl;
    }

}