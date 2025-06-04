#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        deque<int>b,c;
        int count = 0;
        vector<pair<char,char>>v(q);

        for(int i = 0;i<q;i++){
            cin>>v[i].first>>v[i].second;
        }

        for(int i = 0;i<n;i++){
            if(s[i] == 'b')
               b.push_back(i);
            if(s[i] == 'c')
               c.push_back(i);
        }
        for(int i = 0;i<q;i++){
            if(v[i].first == 'b' && v[i].second == 'a' && b.size() > 0 ){
               int ind = b.front();
               b.pop_front();
               s[ind] = 'a';
            }
        }
        for(int i = 0;i<q;i++){
            if(v[i].first == 'b' && v[i].second == 'c' ){
               count++;
            }
            if(v[i].first == 'c' && v[i].second == 'a' && b.size() > 0 && count > 0){
               if(c.size() == 0 || c.front() > b.front()){
                  int ind = b.front();
                  b.pop_front();
                  s[ind] = 'a';
                  count--;
               }
            }
        }
        
    }
}