 #include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
           int n;
           cin>>n;
           map<int,vector<int>[2]>m;
           vector<int>v(n);

           for(int i = 0;i<n;i++){
               int num;
               cin>>num;
               v[i] = num;
                int k = 2;
                num = num >> 2;
                 
               m[num][0].push_back(v[i]);
               m[num][1].push_back(i);
           }

            for(auto &it:m){
                vector<int>nums = it.second[0];
                sort(it.second[1].begin(),it.second[1].end());
                sort(nums.begin(),nums.end());
                for(int i = 0;i<it.second[1].size();i++){
                    v[it.second[1][i]] = nums[i];
                }
            }
          for(int i = 0;i<v.size();i++){
              cout<<v[i]<<" ";
          }
         cout<<endl;
     }
}