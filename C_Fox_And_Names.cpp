#include<bits/stdc++.h>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k){
     vector<vector<int>> adj(k, vector<int>(k, 0));
     vector<int> indegree(k, 0);

     for(int i = 1;i<dictionary.size();i++){
         string s2 = dictionary[i];
         string s1 = dictionary[i-1];
         int flag = 1;
        for(int j = 0;j<min(s1.size(),s2.size());j++){
            if(s1[j] != s2[j]){
                flag = 0;
              if(!adj[s1[j] - 97][s2[j] - 97]) {
                adj[s1[j] - 97][s2[j] - 97] = 1;
                indegree[s2[j] - 97]++;
                }
                break;
            }
        }
        if(flag && dictionary[i].size() < dictionary[i-1].size()) return "a";
     }
      queue<int>q;
          for(int i = 0;i<k;i++){
            if(!indegree[i]){
               q.push(i);
            }
          }
          string s;
          while(!q.empty()){
             int node = q.front();
             q.pop();
             char ch = 97 + node;
             s += ch;
              
             for(int i = 0;i<k;i++){
               if(adj[node][i] == 1){
                  indegree[i]--;
               if(indegree[i] == 0) {
                   q.push(i);
                }
               }
             }
          }
        return s;
}

int main(){
    int n;
    cin>>n;
    vector<string>v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    string s = getAlienLanguage(v,26);
    if(s.size() < 26){
        cout<<"Impossible";
    }
    else{
        cout<<s;
    }

}