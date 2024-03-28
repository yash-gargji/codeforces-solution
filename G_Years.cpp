#include<bits/stdc++.h>
using namespace std;

int main(){
   
        int n;
        cin>>n;
        vector<vector<int>>v;

        for(int i = 0;i<n;i++){
            int f1,f2;
            cin>>f1>>f2;
            v.push_back({f1,f2});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int count = 0;
        int d = -1;
        int k = -1;
        for(int i = 0;i<n;i++){
             if(count == 0 || v[i][0] >= d){
                  count = 1;
                  d = v[i][1];
             }
             else {
                 count++;
                  d = min(d,v[i][1]);
             } 
             cout<<count<<endl;
            if(count > ans){
                k = d-1;
                ans = count;
            }
        }
      cout<<k<<" "<<count<<endl;
}