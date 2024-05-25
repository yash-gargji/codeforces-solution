#include<bits/stdc++.h>
using namespace std;

 int z_function(const string &s, const string &k) {
    string concat = k + '#' + s;
    int n = concat.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && concat[z[i]] == concat[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
        if(i+z[i] == n){
           return z[i];
        }
    }
   return 0;
 }


int main(){
     int n;
     cin>>n;
     vector<string>v;

     for(int i = 0;i<n;i++){
         string s;
         cin>>s;
         v.push_back(s);
     }
     string s = v[0];

     for(int i = 1;i<n;i++){
         int ind = 0;
         if(s.size() >= v[i].size()){
            ind = s.size() - v[i].size();
         }
         
        ind = z_function(s.substr(ind,v[i].size()),v[i]);
        s += v[i].substr(ind,v[i].size() - ind);
     }
    cout<<s<<endl;
} 