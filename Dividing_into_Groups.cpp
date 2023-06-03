#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        multiset<int>s;
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            s.insert(num);
        }
        if(n < k){
            cout<<"0\n";
            continue;
        }
        int sum = 0;
        while(s.size() >= k){
               auto it = s.end();
                vector<int>v;
                   
               for(int i = 0;i<k;i++){
                       it--;
               }
               auto itr = it;
               int num = (*it);
               for(itr = it; itr != s.end() ;itr++){
                     sum = sum + (*itr);
                     int y = (*itr) - num;
                     if(y != 0){
                           v.push_back(y);
                     }
                     s.erase(itr);
               }
               for(int i = 0;i<v.size();i++){
                s.insert(v[i]);
               }
        }
        cout<<sum<<endl;
    }
}