#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        map<string,int>st;
        string s;
        cin>>s;
         for(int i = 0;i<s.size() - 2;i++){
             int a = s[i];
             int b = s[i+1];
             int c = s[i+2];

             s[i] = b;
             s[i+1] = c;
             s[i+2] = a;
             st[s];
              s[i] = a;
              s[i+1] = b;
              s[i+2] = c;
         }
        cout<<st.size()<<endl;
    }
}