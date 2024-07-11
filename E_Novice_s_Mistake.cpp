#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         int n;
         cin>>n;
         string s = to_string(n);
         vector<pair<int,int>>v;

         for(int i = 0;i<1e4;i++){
             for(int j = 0;j<min(7,(int)s.size()-1);j++){
                 int num = stoi(s.substr(0,j+1));
                 if(s.size() == 1){
                     continue;
                 }
                 if(num == n*(i+1) - (s.size() - j - 1)){
                    v.push_back({i+1,s.size() - j - 1});
                 }
             }
            s += to_string(n);
         }
         cout<<v.size()<<endl;

         for(int i = 0;i<v.size();i++){
             cout<<v[i].first<<" "<<v[i].second;
             cout<<endl;
         }
    }
}