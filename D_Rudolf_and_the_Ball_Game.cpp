#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int m,k;
        cin>>m>>k;

       map<int,int>mp;
       mp[k] = 1;

       for(int i = 0;i<m;i++){
           int num;
           char c;
           cin>>num>>c;
           vector<int>v;
           for(auto it:mp){
             v.push_back(it.first);
           }
           mp.clear();
           for(auto it:v){
             if(c == '0'){
                  int l = (it + num - 1) % n+1;
                  mp[l] = 1;
             }
             else if(c == '1'){
                   int l = (it - num - 1 + n) % n+1;
                   mp[l] = 1;
             }
             else {
                 int l = (it + num - 1) % n+1;
                 int p = (it - num - 1 + n) % n+1;
                  mp[l] = 1;
                  mp[p] = 1;
             }
           }
       }
       cout<<mp.size()<<endl;
       for(auto it:mp){
        cout<<it.first<<" ";
       }
       cout<<endl;
    }
}