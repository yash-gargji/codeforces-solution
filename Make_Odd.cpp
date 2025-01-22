#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string a,b;
        cin>>a>>b;

        int ans = 0,sum = 0;

        for(int i = 0;i<a.size();i++){
             if(a[i] == '1' && b[i] == '1')
               ans++;
             else if(a[i] == '1' || b[i] == '1')
               sum++;
        }
        if(ans % 2  || sum > 0)
          cout<<"YES\n";
        else
         cout<<"NO\n";
    }
} 