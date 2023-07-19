#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
         int n;
         cin>>n;
         set<int>s;
         for(int i = 0;i<n;i++){
           int num;
           cin >>num;
           s.insert(num);
         }
        if(s.size() == 1){
            cout<<"NO";
            return 0;
        }
        auto it = s.begin();
        it++;
        cout<<(*it);
 }
