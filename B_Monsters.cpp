#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
          int n;
            cin>>n;
             int k;
             cin>>k;
             map<int,set<int>>m;
             for(int i = 0;i<n;i++){
                int num;
                cin>>num;
                if(num <= k){
                     m[num].insert(i+1);
                }
                else{
                    int f = num/k;
                    if(num%k == 0){
                        f--;
                    }
                    num = num - f*k;
                          m[num].insert(i+1);
                }
             }
                  
             for(auto it = m.rbegin(); it != m.rend() ;it++){
                   auto s = it->second;
                   for(auto &value : s){
                    cout<<value<<" ";
                   }
             }    
             
             cout<<endl;
    }
}
