#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main(){
      int t;
      cin>>t;

      while(t--){
           int n;
           cin>>n;
           vector<pair<int,int>>v;
           pbds os;

           for(int i = 0;i<n;i++){
            int num1,num2;
            cin>>num1>>num2;
                v.push_back({num1,num2});
                 os.insert(num2);
           }
           sort(v.begin(),v.end());
           long long int count = 0;

            for(int i = 0;i<n;i++){
                int b = v[i].second;       
                count = count + os.order_of_key(b);
                os.erase(b);
            }
            cout<<count<<endl;
      }
}