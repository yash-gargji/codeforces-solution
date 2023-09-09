#include<bits/stdc++.h>
using namespace std;

int main(){
       int t;
       cin>>t;
        while(t--){
            int n;
            cin>>n;
           set<int>s;
           s.insert(0);
           for(int i = 1;i<= sqrt(n);i++){
                  int num = n/i;
                s.insert(num);
                s.insert(n/num);
           }
           cout<<s.size()<<endl;

           for(auto val:s){
            cout<<val<<" ";
           }
           cout<<endl;
        }
}