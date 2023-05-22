#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int>m;
        int fl=0;
        for(int i=1;i<n;i++)
        if(s[i]!=s[i-1])
        {
            fl=1;
            break;
            }

        for(int i = 0;i<n;i++){
              m[s[i]]++;
        }
        int odd = 0;
        auto it = m.begin();
        for(it = m.begin(); it != m.end();it++){
           
            if(it->second%2 == 1){
                odd++;
            }
        }
        if(n%2 == 0){
            if(odd >= 1){
                cout<<"0\n";
            }
            else{
                cout<<"1\n";
            }
        }
        else{
            if(fl==0){
                cout<<"2\n";
            }
            else if(odd==1){
                cout<<"1\n";
            }
            else cout<<0<<endl;
        }
    }
}