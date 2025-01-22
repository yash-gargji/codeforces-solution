#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,m;
         cin>>n>>m;
         int ans = 0;

        for(int i = 0;i<n;i++){
            int x,y;
            cin>>x>>y;
             ans+=4*m;
            if(i!=0)
                ans-=2*((m-x)+(m-y));
        }
       cout<<ans<<endl;
    }
}