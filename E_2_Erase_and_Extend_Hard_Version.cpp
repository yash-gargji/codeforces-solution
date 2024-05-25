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

int  main(){
     int n,k;
     cin>>n>>k;
     string p;
     string s;
     if(k < n){
        cin>>s;
     }
     else{
        int l = 0;
        cin>>p;
        while(l< k/n){
            s += p;
            l++;
        }
        p += s.substr(0,k%n);
     }
     int ans = s.size();
     vector<int>z = z_function(s);

     for(int i = 1;i<s.size();i++){
          if(z[i] >= i)
            continue;
          int ind = (i + z[i]);
         if(s[z[i]] < s[ind]){
             ans = i;
             break;
         }
     }
       int num = 0;
        while(num < k/ans){
            cout<<s.substr(0,ans);
            num++;
        }
        for(int i = 0;i<k%ans;i++){
            cout<<s[i];
        }
     
}