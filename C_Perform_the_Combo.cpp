#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
     vector<int>v;
    map<char,int>m2;
    for(int i = 0;i<26;i++){
          char t = 'a' + i;
          m2[t] = 0;
    }
    for(int i = 0;i<n;i++){
        m2[s[i]]++;
    }
    v.push_back(0);
    for(int i = 0;i<m;i++){
       int num;
       cin>>num;
       v.push_back(num);
    }
      int num = m;
     sort(v.begin(),v.end());
      for(int j = 0;j<m;j++){
        for(int i  =v[j] ;i<v[j+1];i++){
           m2[s[i]] = m2[s[i]] + num;
        }
        num--;
      }
      for(auto &value:m2){
            cout<<value.second<<" ";
        }
       cout<<endl;
    }
    return 0;

}