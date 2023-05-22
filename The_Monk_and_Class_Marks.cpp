#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<pair<int,string>>s;

    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        int num;
        cin>>num;
        // num = num - 2*num;
        s.insert({-num,str});
    }
    auto it  = s.begin();
    for(it = s.begin(); it != s.end();it++){
        cout<<it->second<<" "<<-(it->first)<<endl;
    }
 return 0;
}