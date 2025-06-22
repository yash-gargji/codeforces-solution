#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        vector<int>v(6);
        int ma = 0;
        vector<pair<int,int>>p;

        for(int i = 0;i<6;i++){
            cin>>v[i];
            if(i % 2){
                p.push_back({v[i-1],v[i]});
            }
        }
        int fl = 0;
        if(v[0] == v[2] && v[2] == v[4] && v[1] + v[5] + v[3] == v[0]){
          fl = 1;
        }
        if(v[1] == v[3] && v[3] == v[5] && v[0] + v[2] + v[4] == v[1]){
          fl = 1;
        }

        for(int i = 0;i<3;i++){
            int f = 0;
            
        }
        
    }
}