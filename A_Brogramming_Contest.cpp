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
        char k='0';
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]!=k)ans++,k=s[i];
        }
        cout<<ans<<endl;
    }
}