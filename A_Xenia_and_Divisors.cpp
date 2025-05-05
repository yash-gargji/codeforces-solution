#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>v(10);

    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        v[num]++;
    }

    if(v[5] > 0 || v[7] > 0 || v[3] > v[6]){
        cout<<"-1";
        return 0;
    }
    int num = v[6] - v[3];
    if(num + v[4] != v[2]){
        cout<<"-1";
        return 0;
    }
    if(v[2] != v[1] - v[3]){
      cout<<"-1\0";
      return 0;
    }
    vector<vector<int>>ans;

    while(v[3] > 0){
        ans.push_back({1,3,6});
        v[1]--;
        v[3]--;
        v[6]--;
    }
    while(v[2] > 0){
       if(v[4] > 0){
          ans.push_back({1,2,4});
          v[1]--;
          v[2]--;
          v[4]--;
       }
       else{
        ans.push_back({1,2,6});
        v[1]--;
        v[2]--;
        v[6]--;
       }
    }
    sort(ans.begin(),ans.end());

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}