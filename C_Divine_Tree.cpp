#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        if(n*(n+1) /2  < m){
           cout<<"-1\n";
           continue;
        }
        vector<int>v;
        vector<pair<int,int>>edg;
        int prev = -1;

        int sum = 0;
        int root = -1;

        for(int i = n;i >= 1;i--){
            if(sum + 2*i - 1 + v.size() <= m){
                if(root == -1){
                    root = i;
                }
                sum += i;
                if(prev != -1)
                  edg.push_back({prev,i});
                prev = i;
            }
            else{
                v.push_back(i);
            }
        }
        for(int i = 0;i<v.size();i++)
            edg.push_back({1,v[i]});
        
        if(sum + v.size() != m){
           cout<<"-1\n";
           continue;
        }
        cout<<root<<endl;
        for(int i = 0;i<edg.size();i++){
            cout<<edg[i].first<<" "<<edg[i].second<<endl;
        }
    }
}