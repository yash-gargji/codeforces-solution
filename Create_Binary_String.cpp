#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;

        int ans = 0;
        for(int i = 0;i<=n;i++){
            int x = i,y = n - i;
            ans = max(ans,x*a + y*b + x*y*c);
            ans = max(ans,x*a + y*b + x*y*d);
        }
        cout<<ans<<endl;
    }
}