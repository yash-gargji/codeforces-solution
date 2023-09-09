#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        set<int>s;
        int ans = 0;
        int prev ;
        for(int i = 0;i<n;i++){
              int num;
              cin>>num;
             auto it =  s.find(num);
             if(it == s.end()){
                s.insert(num);
                   if(s.size() >= ans){
                   ans = s.size();
              }
             }
              
              else{
                s.erase(it);
        }
  
        }
        cout<<ans<<endl;
    }
}