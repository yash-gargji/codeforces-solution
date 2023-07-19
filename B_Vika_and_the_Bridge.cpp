#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        map<int,deque<int>>m;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            m[num].push_back(i);
        }
        int ans = 2e5 + 1;

        for(auto &value:m){
            auto it = value.second;
            it.push_front(0);
             it.push_back(n);
             priority_queue<int>p;

             for(int i = 1;i<it.size();i++){
                   if(i == 1){
                     p.push(it[i]);
                   }
                   else{
                    p.push(it[i] - it[i-1] - 1);
                   }
             }
             
             int x = p.top();
                p.pop();
                int y = p.top();
                ans = min(ans,max(x/2,y));
                if(ans == 0){
                    break;
                }
        }
        cout<<ans<<endl;
    }
}