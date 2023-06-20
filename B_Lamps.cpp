#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,multiset<int>>m;
        for(int i = 0;i<n;i++){
            int x,y;
            cin>>x>>y;
            m[x].insert(y);
        }
        long long int sum = 0;
        for(auto &value:m){
            int num = value.first;
            auto &s = value.second;
            for(auto it = s.rbegin(); it != s.rend(); it++){
                if(num == 0){
                    break;
                }
                   sum = sum +  (*it);
                   num--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}