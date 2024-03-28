#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    unordered_map<string,int>m;
    int num = -1001;
    string ans;
    for(int i = 0;i<t;i++){
            string s;
            cin>>s;
            int a;
            cin>>a;
            m[s] = m[s] + a;    
           if(m[s] > num){
                num = m[s];
                ans = s;
           }      
    }
     cout<<ans;  
}