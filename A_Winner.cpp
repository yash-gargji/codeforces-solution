#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    unordered_map<string,int>m;
    pair<string,int>p[t];
    int max = -1001;
    string ans;
    for(int i = 0;i<t;i++){
            string s;
            cin>>s;
            int a;
            cin>>a;
            p[i] = {s,a};
            m[s] = m[s] + a;          
    }
       map<int,int>m1;
       for(auto &value:m){
           m1[value.second]++;
       }
       auto it = m1.end();
         it = it-1;

}