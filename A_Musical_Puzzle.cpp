#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        string s;
        cin>>s;
        set<string>s1;
        for(int i = 0;i<a-1;i++){
            string num;
            num = s[i] ;
            num = num + s[i+1];
            s1.insert(num);
        }
        cout<<s1.size()<<endl;
    }
}