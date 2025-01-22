#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>v(2*n+1,1);
        map<int,int>mp;
        vector<vector<int>>p;
        
        for(int i = 0;i<n;i++){
            int l,r;
            cin>>l>>r;
            if(l == r){
                mp[l]++;
                v[l] = 0;
            }
            p.push_back({l,r});
        }
        for(int i = 1;i<= 2*n;i++){
            v[i] += v[i-1];
        }
        for(int i = 0;i<n;i++){
            int l = p[i][0];
            int r = p[i][1];
            if(l == r && mp[l] > 1){
               cout<<0;
            }
            else if(v[r] - v[l-1] == 0 && l != r){
               cout<<0;
            }
            else{
                cout<<"1";
            }
        }
      cout<<endl;
    }
}