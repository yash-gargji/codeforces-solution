#include<bits/stdc++.h>
using namespace std;

void solve(){
        int n;
        cin>>n;
        vector<int>adj[n+1];
        int ma = 0,ans = -1;

        for(int i = 1;i<= n;i++){
            cout<<"? "<<i<<" "<<n<<" ";
            for(int j = 1;j<= n;j++){
                cout<<j<<" ";
            }
            cout<<endl;
            int num;
            cin>>num;
            adj[num].push_back(i);
            if(num > ma){
              ans = i;
              ma = num;
            }
        }
        int node = ans;
        vector<int>v;
        v.push_back(node);

        for(int i = ma-1;i > 0;i--){
            for(auto it:adj[i]){
            cout<<"? "<<node<<" "<<2<<" "<<node<<" "<<it<<endl;
            int num;
            cin>>num;
            if(num == 2){
                v.push_back(it);
                node = it;
            }
            }
        }
        cout<<"! "<<v.size()<<" ";
        for(int i = 0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}