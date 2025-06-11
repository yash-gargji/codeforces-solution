#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;
        string s;
        cin>>n>>q>>s;

        deque<int>b,c,st;
        int count = 0,temp = 0;
        vector<pair<char,char>>v(q);

        for(int i = 0;i<q;i++){
            cin>>v[i].first>>v[i].second;
            if(v[i].first == 'c' && v[i].second == 'a' ){
               st.push_back(i);
            }
        }
        for(int i = 0;i<n;i++){
            if(s[i] == 'b')
               b.push_back(i);
            if(s[i] == 'c')
               c.push_back(i);
        }
         for(int i = 0;i<q;i++){
            if(v[i].first == 'c' && v[i].second == 'b' ){
               temp++;
            }
            while(st.size() > 0 && c.size() > 0 && (b.size() == 0 || b.front() > c.front())){
                 int ind = c.front();
                 c.pop_front();
                 s[ind] = 'a';
                 st.pop_front();
            }
            if(v[i].first == 'b' && v[i].second == 'a' && c.size() > 0 && temp > 0 && (b.size() == 0 || b.front() > c.front())){
                int ind = c.front();
                c.pop_front();
                s[ind] = 'a';
                temp--;
                continue;
            }
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
            if(st.size() == 0 || st.front() != i)
               continue;
            st.pop_front();
            if(b.size() > 0 && count > 0 && (c.size() == 0 || c.front() > b.front())){
                int ind = b.front();
                b.pop_front();
                s[ind] = 'a';
                count--;
                continue;
            }
            if(c.size() > 0 ){
                 int ind = c.front();
                 c.pop_front();
                 s[ind] = 'a';
            }
        }
        while(temp > 0 && c.size() > 0 ){
             int ind = c.front();
             c.pop_front();
             s[ind] = 'b';
             temp--;
        }

        cout<<s<<endl;
    }
}