#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int ans = -1;
        int flag = 0;
        vector<int>v;
        
        map<int,int>m;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            m[num]++;
            if(m[num] >= 4){
                v.resize(4,num);
                flag = 2;
            }
            if(m[num] >= 2){
               ans = max(ans,num);
            }
        }
        if(flag == 2){
            for(int i = 0;i<4;i++){
                cout<<v[0]<<" ";
            }
            cout<<endl;
            continue;
        }
        if(ans == -1){
          cout<<ans<<endl;
          continue;
        }
        v.push_back(ans);
        v.push_back(ans);
        m[ans]-=2;
        int prev = -1;

        for(auto it:m){
            if(it.second == 0)
              continue;
            if(it.second >= 2){
                 v.push_back(it.first);
                 v.push_back(it.first);
                 break;
            }
            if(prev != - 1 && abs(it.first - prev)/2 < ans){
                v.push_back(prev);
                v.push_back(it.first);
                break;
            }
            prev = it.first;
        }
        if(v.size() != 4){
             cout<<"-1\n";
        }
        else{
            for(int i = 0;i<4;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}