#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        unordered_map<string,vector<int>>mp;
        vector<string>arr;

        for(int j = 0;j<n;j++){
            string s;
            cin>>s;
            arr.push_back(s);

            for(int i = 0;i<m-1;i++){
                mp[s.substr(i,2)] = {j+1,i+1,i+2};
                if(i != m-2){
                   mp[s.substr(i,3)] = {j+1,i+1,i+3};
                }
            }
        }
        string s;
        cin>>s;

        int f = 1;
        int ind = -1;
        vector<vector<int>>ans;

        for(int i = 0;i<m;i++){
            if(i != m-1 && mp.count(s.substr(i,2))){
               ans.push_back(mp[s.substr(i,2)]);
               i++;
               continue;
            }
            char c = s[i];
            int j = ans.size()-1;
            int flag = -1;

            while(j > ind){
               string k = arr[ans[j][0]-1].substr(ans[j][1]-1,ans[j][2] - ans[j][1] + 1);
               for(int l = 0;l<k.size();l++){
                   string p = k.substr(l,k.size()-l) + c;
                   if(mp.count(p)){
                      ans[j] = mp[p];
                      flag = l;
                      break;
                   }
               }
               if(flag == -1 || flag == 0)
                  break;
                c = k[0];
                j--;
                flag = -1;
            }
            if(flag != 0){
               f = 0;
               break;
            }
            ind = ans.size()-1;
        }  

        if(f == 0){
           cout<<"-1\n";
           continue;
        }
        cout<<ans.size()<<endl;
        for(int i = 0;i<ans.size();i++)
            cout<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][0]<<endl;
    }
}
