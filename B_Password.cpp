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
    int flag = 0;
    int ma = 0;

    for(int i = 0;i<s.size();i++){
        if(i+z[i] == s.size() && ma >= z[i]){
            cout<<s.substr(0,z[i]);
            flag = 1;
            break;
        }
        ma = max(ma,z[i]);
        
    }
    if(flag == 0)
      cout<<"Just a legend";
}