#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int n,m;
         cin>>n>>m;
        map<int,multiset<int>>s;

         for(int i = 0;i<n;i++){
           for(int j = 0;j<m;j++){
            int num;
            cin>>num;
            s[j].insert(num);
           }
         }
         vector<long long int>v(n);

         for(auto it = s.begin(); it != s.end();it++){
                 int j = 0;
                 auto &s = it->second;

                 for(auto &value: s){
                     v[j] = v[j] + value;
                     j++;
                 }
         }
         long long int pre[n];
         pre[0] = v[0];
         for(int i= 1;i<n;i++){
           pre[i] = pre[i-1] + v[i];
         }
         long long int sum = 0;
         for(int i = n-1;i>0;i--){
          sum = sum + i*v[i] - pre[i-1];
         }
         cout<<sum<<endl;
    }
    return 0;
}