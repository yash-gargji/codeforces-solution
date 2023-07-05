#include<bits/stdc++.h>
using namespace std;

int main(){
       int a,b;
       cin>>a>>b;
       string s = to_string(b);
       reverse(s.begin(),s.end());
       b = stoi(s);
       cout<<a+b;
       return 0;
}