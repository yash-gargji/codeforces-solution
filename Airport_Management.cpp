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
        map<long long int,long long int>m;
        for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             m[num]++;
        }  
          for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             m[num]++;
        }  
        long long int ans = 0;
        for(auto it = m.begin() ;it != m.end() ; it++){
                  ans = max(ans,it->second);
        }
        cout<<ans<<endl;
        
    }
}