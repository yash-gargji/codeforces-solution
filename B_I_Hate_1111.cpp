#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        string s;
        cin>>s;
        long long int x;
        int a = s.size();
        x = stoi(s);
        if(x < 10)
        {
            cout<<"NO\n";
            continue;
        }
        if(s[a-1] == s[a-2])
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";

    }
}  