#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        map<int,vector<int>>m;
        map<int,int>vis;
        int arr[n];

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            arr[i] = num;
            m[num].push_back(i);
        }
        vector<int>ans;
        for(int i = 0 ;i<n;i++){
           if(vis[arr[i]])
             continue;
            int o = 1,e = 1;
            int j = ans.size() - 1;
            int updt = -1;
            while(j >= 0 && (o == 1 || e == 1)){
                if(m[ans[j]][m[ans[j]].size() - 1] < i)
                    break;
                if((j+1) % 2 == 1){
                    if(arr[i] > ans[j]){
                        updt = j;
                    }
                    else
                      o = 0;
                }
                else{
                    if(arr[i] < ans[j]){
                        updt = j;
                    }
                    else
                      e = 0;
                }
               j--;
            }
            if(updt != -1)
              while(ans.size() != updt){
                    vis[ans[ans.size() - 1]] = 0;
                    ans.pop_back();
              }
            ans.push_back(arr[i]);
            vis[arr[i]] = 1;
        }
        cout<<ans.size()<<endl;
       for(int i = 0;i<ans.size();i++){
          cout<<ans[i]<<" ";
       }
       cout<<endl;
    }
}