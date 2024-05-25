#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    string s;
    cin>>s;

    vector<int>z = z_function(s);
    vector<int>d(s.size()+2,0);
    map<int,int>m;
    z[0] = s.size();

    for(int i = 0;i<s.size();i++){
        if(i+z[i] == s.size()){
           m[z[i]] = 1;
        }
        if(z[i] > 0){
            d[0]++;
            d[z[i]+1]--;
        }  
    }
   for(int i = 1;i<=s.size();i++){
       d[i] += d[i-1];
   }
   cout<<m.size()<<endl;

   for(auto it:m){
       cout<<it.first<<" "<<d[it.first]<<endl;
   }
}